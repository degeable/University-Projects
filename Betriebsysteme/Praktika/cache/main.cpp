/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: stud
 *
 * Created on 5. Januar 2018, 13:56
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <queue>
#include <list>
#include <algorithm>
#include <unistd.h>
#include <stdio.h>
#include <map>
using namespace std;

/*
 * 
 */



struct block {
    string text;
    int block_id;
    time_t used;

    block() : block_id(-1) {

    };

    block(int ID, string Text) : block_id(ID), used(time(0)) {
        text = Text;
        text.reserve(1024);
    }

    block(int ID, string Text, int us) : block_id(ID), used(time(0)) {
        text = Text;
        text.reserve(1024);
    }

    friend std::ostream& operator<<(std::ostream& os, const block& s) {
        os << s.block_id << "\n" << s.text << "\n" << s.used << "\n";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, block& s) {
        is >> s.block_id >> s.text >> s.used;
        return is;
    }

    virtual ~block() {

    }


};


int total = 0;
int RAM = 0;
int used_blocks = 0;

ofstream save;
ifstream load;
vector<block>ram; //=new vector<block>(0);
map<int, bool>belegt;

void init_store(int total_blocks, int ram_blocks) {
    string buffer;
    buffer.resize(1024, ' ');
    ofstream save;
    for (int i = 0; i < total_blocks; i++) {
        save.open("./" + to_string(i));
        save << buffer;
        save.close();
        belegt.insert(std::pair<int, bool>(i, false));

    }



    for (int i = 0; i < ram_blocks; i++) {
        ram.push_back(block());
        ram.at(i).text = buffer;
    }
    total = total_blocks;
    RAM = ram_blocks;
}

void cleanup_store() {
    ram.clear();
    for (int i = 0; i < total; i++) {
        remove(("./" + to_string(i)).c_str());
    }
}

int SaveToHdd(int pos) {

    if (ram.at(pos).block_id != -1 && ram.at(pos).block_id < total) {
        save.open("./" + to_string(ram.at(pos).block_id));
        save << ram.at(pos).text;
        save.close();

        cout << "[" << ram.at(pos).block_id << "]" << " wurde auf Platte ausgelagert" << endl;


        return 0;
    }

    return -1;
}

int lru() {

     
    int it = 0;
    for (int i = 0; i < RAM; i++) {
         if(ram.at(i).block_id==-1)
             return i;
        if (ram.at(it).used > ram.at(i).used) {
            it = i;
        }
    }

    return it;

}

int writeCacheBlock(int blockID, string buffer) {
    buffer.resize(1024);
    if (blockID != -1 && blockID < total) {
        for (int i = 0; i < RAM; i++) {
            if (ram.at(i).block_id == blockID) {
                ram.at(i).text = buffer;
                ram.at(i).used = time(0);
                cout << "[" << blockID << "]" << " wurde im RAM geschrieben" << endl;
                return 0;
            }
        }

 
        int pos = lru();
        SaveToHdd(pos);
        save.open("./" + to_string(blockID));
        save << buffer;
        save.close();
        belegt[blockID] = true;
        ram.at(pos).block_id = blockID;
        ram.at(pos).text = buffer;
        ram.at(pos).used = time(0);
        cout << "[" << blockID << "]" << " wurde in RAM geladen und beschrieben" << endl;
        return 0;
    } else if(blockID==-1) {
        for (int i = 0; i < total; i++) {
            if (belegt[i] == false) {
                cout << "freier Block gefunden:" << i << endl;
                writeCacheBlock(i, buffer);
                return i;
            }
        }
           cout<<"kein freier Block mehr vorhanden!"<<endl;
           return -1;
    }else if(blockID>=total){
        cout<<"Ungueltige Block ID!"<<endl;
        return -1;
   
    }
}

int readCacheBlock(int blockID, string &buffer) {
    string empty;
    empty.resize(1024,' ');
     if (blockID >= 0 && blockID < total) {
    for (int i = 0; i < RAM; i++) {
        if (ram.at(i).block_id == blockID) {
            buffer = ram.at(i).text;
            if(buffer==empty)
                buffer="Block ist leer!";
            ram.at(i).used = time(0);
            cout << "[" << blockID << "]" << " HIT->Block vorhanden:" << buffer << endl;

            return 0;
        }


    }

  //  if (access(("./" + to_string(blockID)).c_str(), F_OK)) {
        for (int i = 0; i < RAM; i++) {
            if (ram.at(i).block_id == -1) {
                load.open("./" + to_string(blockID));
                getline(load, ram.at(i).text);
                ram.at(i).block_id = blockID;
                ram.at(i).used = time(0);
                load.close();
                buffer = ram.at(i).text;
                   if(buffer==empty)
                buffer="Block ist leer!";
                cout << "[" << blockID << "]" << " MISS->Block wurde von Platte geladen: "<<buffer << endl;
                return 0;
            }
        }

        int pos = lru();
        SaveToHdd(pos);
        load.open("./" + to_string(blockID));
        getline(load, ram.at(pos).text);
        ram.at(pos).block_id = blockID;
        ram.at(pos).used = time(0);
        load.close();
        buffer = ram.at(pos).text;
           if(buffer==empty)
                buffer="Block ist leer!";
        cout << "[" << blockID << "]" << " MISS->Block wurde von Platte geladen: "<<buffer << endl;
        return 0;

    }
    cout << "[" << blockID << "]" << " Block nicht vorhanden" << endl;
    return -1;
}

int freeCacheBlock(int blockID) {
    string empty;
    empty.resize(1024, ' ');
    if (blockID >= 0 && blockID < total) {
        for (int i = 0; i < RAM; i++) {
            if (ram.at(i).block_id == blockID) {
                ram.at(i).text = empty;
                ram.at(i).block_id = -1;
                SaveToHdd(i);
                belegt[blockID]=false;
                cout << "[" << blockID << "]" << "Cleared" << endl;
                return 0;
            }
        }
        save.open("./" + to_string(blockID));
        save << empty;
        save.close();
        return 0;

    }
    return -1;
}

int main(int argc, char** argv) {
    string buffer;
    init_store(3, 2);
    int auswahl=-1;
    int block = 0;
    while (auswahl != 0) {
        cout << "\n1. Write" << endl;
        cout << "2. Read" << endl;
        cout << "3. Clear" << endl;
        cout << "4. Show Ram"<< endl;
        cout << "0. Exit" << endl<<endl<<endl;;
        cin>>auswahl;
        switch (auswahl) {
            case 1: cout << "Block: ";
                cin>>block;
                cout << "\nText: ";
                cin>>buffer;
                writeCacheBlock(block, buffer);
                break;
            case 2: cout << "Block: ";
                cin>>block;
                readCacheBlock(block,buffer);
                break;
            case 3: cout << "Block: ";
                cin>>block;
                freeCacheBlock(block);
                break;
            case 4: 
                for (int i = 0; i < RAM; i++) {
                cout<<"["<<ram.at(i).block_id<<"]"<<"zuletzt vor "<<time(0) - ram.at(i).used<<" Sekunden genutzt"<<endl;
                }
                break;
            case 0: break;
        }

    }


    cleanup_store();
    return 0;
}

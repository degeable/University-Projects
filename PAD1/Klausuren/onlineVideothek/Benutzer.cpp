/* 
 * File:   Benutzer.cpp
 * Author: fs
 * 
 * Created on 2. Februar 2017, 13:19
 */

#include "Benutzer.h"
#include <iostream>
using namespace std;

Benutzer::Benutzer(string Name, string Pwd) {
    name=Name;
    pwd=Pwd;
    currentVideo=-1;
}


Benutzer::~Benutzer() {
}

string Benutzer::GetName() const {
    return name;
}

string Benutzer::GetPwd() const {
    return pwd;
}

vector<int>& Benutzer::GetListe()  {
    return liste;
}

void Benutzer::SetCurrentVideo(int currentVideo) {
    this->currentVideo = currentVideo;
}

int Benutzer::GetCurrentVideo() const {
    return currentVideo;
}

//void Benutzer::printFav() {
//    for(auto i=0;i<liste.size();i++)
//    cout<<"ID: "<<liste.at(i)<<endl;
//    cout<<"Titel: "<<name<<endl<<endl;
//}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DungeonMap.cpp
 * Author: stud
 * 
 * Created on 25. April 2017, 13:20
 */

#include <cstring>
#include <fstream>
#include <sstream>
#include "DungeonMap.h"
#include "Switch.h"
#include "StationaryController.h"
#include "AttackController.h"
#include "Lever.h"
#include "Trap.h"
#include "Item.h"
#include "Position.h"

DungeonMap::DungeonMap(int height, int width)
{

    m_height = height;
    m_width = width;
    m_map = new Tile**[height];


    for (auto i = 0; i < height; i++)
    {
        m_map[i] = new Tile*[width];
        for (auto j = 0; j < width; j++)
        {
            m_map[i][j] = new Tile(nullptr);
        }
    }



}

DungeonMap::DungeonMap(int height, int width, const vector<string>& data, const vector<string>& data_s)
{

    m_height = height;
    m_width = width;
    m_map = new Tile**[height];
    for (auto i = 0; i < height; i++)
    {
        m_map[i] = new Tile*[width];
        for (auto j = 0; j < width; j++)
        {

            if (data.at(i).at(j) == '.')
            {
                m_map[i][j] = new Floor(nullptr);
            }
            else if (data.at(i).at(j) == '#')
            {
                m_map[i][j] = new Wall(nullptr);
            }
        }
    }


}

DungeonMap::~DungeonMap()
{
    for (int i = 0; i < m_height; i++)
    {
        for (int j = 0; j < m_width; j++)
        {
            delete m_map[i][j];
        }
        delete [] m_map[i];

    }
    delete[] m_map;


}

Position DungeonMap::findCharacter(Character* c) const
{
    for (auto i = 0; i < m_height; i++)
    {
        for (auto j = 0; j < m_width; j++)
        {
            if (m_map[i][j]->GetFigur() == c)
            {
                Position p;
                p.Reihe = i;
                p.Spalte = j;
                return p;
            }
        }
    }
    throw invalid_argument("Kein Character vorhanden");

}

Position DungeonMap::findTile(Tile* t) const
{
    for (auto i = 0; i < m_height; i++)
    {
        for (auto j = 0; j < m_width; j++)
        {
            if (m_map[i][j] == t)
            {
                Position p;
                p.Reihe = i;
                p.Spalte = j;
                return p;
            }
        }
    }
    throw invalid_argument("Tile nicht gefunden");
}

Tile* DungeonMap::findTile(Position pos) const
{
    if (pos.Reihe > m_height || pos.Spalte > m_width)
        throw out_of_range("Gesuchtes Tile außerhalb des Spielfelds");
    return m_map[pos.Reihe][pos.Spalte];
}

Tile* DungeonMap::findTile(int Reihe, int Spalte) const
{
    if (Reihe > m_height || Spalte > m_width)
        throw out_of_range("Gesuchtes Tile außerhalb des Spielfelds");
    return m_map[Reihe][Spalte];
}

void DungeonMap::place(Position pos, Character* c)
{
    m_map[pos.Reihe][pos.Spalte]->SetFigur(c);

}

void DungeonMap::print(Position pos) const
{
    Position Start;

    for (auto i = 0; i < m_height; i++)
    {
        for (auto j = 0; j < m_width; j++)
        {
            Start.Reihe = i;
            Start.Spalte = j;
            if (hasLineofSight(Start, pos) == true)
            {
                m_map[i][j]->print();
            }
            if (hasLineofSight(Start, pos) == false)
            {
                cout << "#";


            }


        }
        cout << endl;

    }
    cout << endl << endl;
}

bool DungeonMap::hasLineofSight(Position pStart, Position pDest) const //sehr naiver Algorythmus... 
{


    int x0 = pStart.Reihe;
    int y0 = pStart.Spalte;
    int x1 = pDest.Reihe;
    int y1 = pDest.Spalte;
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = dx + dy, e2;


    while (1)
    {
        if (findTile(x0, y0)->isTransparent())
        {
            if (x0 == x1 && y0 == y1) break;
            e2 = 2 * err;
            if (e2 > dy)
            {
                err += dy;
                x0 += sx;
            }
            if (e2 < dx)
            {
                err += dx;
                y0 += sy;
            }
        }
        else
        {
            return false;
        }
    }
    return true;
}

vector<Character*> DungeonMap::Parse(vector<string>data_s)
{
    stringstream daten;
    char id;
    vector<Character*>figuren;
    Character* spieler=nullptr;

    for (int i = 0; i < data_s.size(); i++)
    {
        daten << data_s.at(i);
        daten>>id;
        if (id == 'C')
        {
            char symbol;
            int Reihe;
            int Spalte;
            int Stamina;
            int Strength;
            char cntrl;
            daten >> symbol >> Stamina >> Strength >> Reihe >> Spalte>>cntrl;
            if (cntrl == 'C')
            {
                Controller* contr_ptr = new ConsoleController(nullptr);
                Character* p = new Character(symbol, contr_ptr, Strength, Stamina);
                contr_ptr->setC_figur(p);
                Position pos;
                pos.Reihe = Reihe;
                pos.Spalte = Spalte;
                this->place(pos, p);
                figuren.push_back(p);
                spieler=p;

            }
            else if (cntrl == 'S')
            {
                Controller* contr_ptr = new StationaryController(nullptr);
                Character* p = new Character(symbol, contr_ptr, Strength, Stamina);
                contr_ptr->setC_figur(p);
                Position pos;
                pos.Reihe = Reihe;
                pos.Spalte = Spalte;
                this->place(pos, p);
                figuren.push_back(p);
            }
            else if (cntrl == 'A')
            {
              
                Controller* contr_ptr = new AttackController(nullptr,this,spieler);
                  Character* p = new Character(symbol, contr_ptr, Strength, Stamina);
                  contr_ptr->setC_figur(p);
                Position pos;
                pos.Reihe = Reihe;
                pos.Spalte = Spalte;
                this->place(pos, p);
                figuren.push_back(p);
            }
            daten.clear();
        }
        if (id == 'D')
        {
            int Door_Reihe;
            int Active_Spalte;
            int Active_Reihe;
            int Door_Spalte;
            char ID;
            daten >> Door_Reihe >> Door_Spalte >> ID >> Active_Reihe>>Active_Spalte;
            if (ID == 'S')
            {




                Door* door_ptr = new Door(nullptr);
                delete m_map[Door_Reihe][Door_Spalte];
                m_map[Door_Reihe][Door_Spalte] = door_ptr;

                delete m_map[Active_Reihe][Active_Spalte];
                m_map[Active_Reihe][Active_Spalte] = new Switch(nullptr, door_ptr);
            }
            else if (ID == 'L')
            {


                Door* door_ptr = new Door(nullptr);
                delete m_map[Door_Reihe][Door_Spalte];
                m_map[Door_Reihe][Door_Spalte] = door_ptr;

                delete m_map[Active_Reihe][Active_Spalte];
                m_map[Active_Reihe][Active_Spalte] = new Lever(nullptr, door_ptr);

            }
            daten.clear();
        }

        if (id == 'T')
        {
            {
                int T_Reihe;
                int T_Spalte;
                daten >> T_Reihe>>T_Spalte;
                delete m_map[T_Reihe][T_Spalte];
                m_map[T_Reihe][T_Spalte] = new Trap(nullptr);

            }
            daten.clear();
        }

        if (id == 'I')
        {
            string i_id;
            int I_Reihe;
            int I_Spalte;
            daten >> i_id >> I_Reihe>>I_Spalte;


            if (i_id == "AS")
            {
                m_map[I_Reihe][I_Spalte]->setItem(new ArmingSword);
            }
            else if (i_id == "GS")
            {
                m_map[I_Reihe][I_Spalte]->setItem(new GreatSword);
            }
            else if (i_id == "CL")
            {
                m_map[I_Reihe][I_Spalte]->setItem(new Club);
            }
            else if (i_id == "RD")
            {
                m_map[I_Reihe][I_Spalte]->setItem(new RapierAndDagger);
            }
            else if (i_id == "GB")
            {
                m_map[I_Reihe][I_Spalte]->setItem(new Gambeson);
            }
            else if (i_id == "MA")
            {
                m_map[I_Reihe][I_Spalte]->setItem(new MailArmour);
            }
            else if (i_id == "SH")
            {
                m_map[I_Reihe][I_Spalte]->setItem(new Shield);
            }
            else if (i_id == "FR")
            {
                m_map[I_Reihe][I_Spalte]->setItem(new FullPlateArmour);
            }
            daten.clear();
        }
    }
    return figuren;
}



vector<Position> DungeonMap::getPathto(Position from, Position to)
{
    //https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm#Pseudocode

    vector<Position> weg;
    set<Position> Q, Q2;
    map<Position, Position> prev;
    map<Position, int> dist;


    Position pos(0, 0);
    for (pos; pos.Reihe < m_height; pos.Reihe++) {
        for (pos; pos.Spalte < m_width; pos.Spalte++) {
            if (findTile(pos)->istBetretbar()) { //nur begehbare tiles
                Q.insert(pos); 
                dist[pos] = numeric_limits<int>::max()-1; //distanz vorerst unendlich
                prev[pos] = Position(-1, -1); //-1,-1 steht für unglültig...

            }
        }
        pos.Spalte = 0; 
    }
    
    Q2 = Q;

    dist[from] = 0; //erste dist ist 0

    
    while (Q.size()!= 0) {  //loop für alle elemente
        Position u = (*Q.begin()); //erste Position
        
        for (auto itQ = Q.begin(); itQ != Q.end(); itQ++) { //die Kürzeste Distanz wird gesucht... in der ersten Runde ist es die Startposition
            if (dist[*itQ] < dist[u]) { 
                u = (*itQ); 
            }
        }


        Q.erase(u); //entferne element mit kleinster distanz 


        for (int i = -1; i < 2; i++) { //alle nachbarn anschauen und Distanz und Vorgänger setzen...
            for (int j = -1; j < 2; j++) {
                Position newPos = Position(u.Reihe + i, u.Spalte + j);
                auto newItPos = Q2.find(newPos); //für die Prüfung ob wir am Ende sind (2zeilen weiter
                int newDist = dist[u] + 1; //die neue Distanz von den Nachbarn ist immer 1
                if (newDist < dist[newPos] && newItPos != Q2.end()) { //wenn die Distanz kleiner ist und man nicht am ende ist
                    dist[newPos] = newDist; //neue distanz setzen
                    prev[newPos] = u; //vorgänger setzen
                }
            }
        }

    }
    
    Position currentPos = to;
    while (currentPos != from){ //ueberpruefe ob letzes element gleich dem startpunkt ist
        weg.push_back(currentPos); //speichere letzte pos
        currentPos = prev[currentPos]; //hole vorgänger
    }


    reverse(weg.begin(), weg.end()); //vektor umdrehen damit reihenfolge stimmt.

    return weg;
}


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

#include "DungeonMap.h"
#include "Switch.h"
#include "StationaryController.h"
#include "Lever.h"
#include "Trap.h"
#include "Item.h"

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
                        Start.Reihe=i;
                        Start.Spalte=j;
                       if(hasLineofSight(Start,pos)==true){
            m_map[i][j]->print();
                       }
                               if(hasLineofSight(Start,pos)==false){
                           cout<<"#";


            }


        }
        cout << endl;

    }
    cout << endl << endl;
}

bool DungeonMap::hasLineofSight(Position pStart, Position pDest) const //sehr naiver Algorythmus... 
{

   
   int x0=pStart.Reihe;
   int y0=pStart.Spalte;
   int x1=pDest.Reihe;
   int y1=pStart.Spalte;
 int dx =  abs(x1-x0), sx = x0<x1 ? 1 : -1;
  int dy = -abs(y1-y0), sy = y0<y1 ? 1 : -1;
  int err = dx+dy, e2; /* error value e_xy */
   

  while(1){
    if (findTile(x0,y0)->isTransparent()){
    if (x0==x1 && y0==y1) break;
    e2 = 2*err;
    if (e2 > dy) { err += dy; x0 += sx; } /* e_xy+e_x > 0 */
    if (e2 < dx) { err += dx; y0 += sy; } /* e_xy+e_y < 0 */
    }else{return false;}
  }
  return true;
}
//    int difR;
//    int difS;
//    if (pStart.Reihe >= pDest.Reihe)
//    {
//        difR = pStart.Reihe - pDest.Reihe;
//    }
//    else
//    {
//        difR = pDest.Reihe - pStart.Reihe;
//    }
//
//    if (pStart.Spalte >= pDest.Spalte)
//    {
//        difS = pStart.Spalte - pDest.Spalte;
//    }
//    else
//    {
//        difS = pDest.Spalte - pStart.Spalte;
//    }
//
//    while (pStart.Reihe != pDest.Reihe || pStart.Spalte != pStart.Spalte)
//    {
//
//        if (findTile(pStart)->isTransparent())
//        {
//            if (pStart.Reihe >= pDest.Reihe)
//            {
//                difR = pStart.Reihe - pDest.Reihe;
//            }
//            else
//            {
//                difR = pDest.Reihe - pStart.Reihe;
//            }
//
//            if (pStart.Spalte >= pDest.Spalte)
//            {
//                difS = pStart.Spalte - pDest.Spalte;
//            }
//            else
//            {
//                difS = pDest.Spalte - pStart.Spalte;
//            }
//
//            if (difR <= difS)
//            {
//                if (pStart.Spalte > pDest.Spalte)
//                {
//                    pStart.Spalte--;
//                }
//                else pStart.Spalte++;
//            }
//            else
//                if (pStart.Reihe > pDest.Reihe)
//            {
//                pStart.Reihe--;
//            }
//            else pStart.Reihe++;
//        }
//        else return false;
//    }
//    return true;
//



Character* DungeonMap::Parse(vector<string>data_s, int i)
{
    char t = static_cast<char> (data_s.at(i).at(0)); //Befehls ID und dann If abfragen für alles...
    if (strncmp(&t, "C", 1) == 0)
    {

        string Cha_Ctrl = data_s.at(i).substr(10, 1);
        int Reihe = static_cast<int> (data_s.at(i).substr(6, 1).at(0) - 48)*10 + (static_cast<int> (data_s.at(i).substr(7, 1).at(0) - 48));
        int Spalte = static_cast<int> (data_s.at(i).substr(8, 1).at(0) - 48)*10 + (static_cast<int> (data_s.at(i).substr(9, 1).at(0) - 48));
        int Stamina = static_cast<int> (data_s.at(i).substr(2, 1).at(0) - 48)*10 + (static_cast<int> (data_s.at(i).substr(3, 1).at(0) - 48));
        int Strength = static_cast<int> (data_s.at(i).substr(4, 1).at(0) - 48)*10 + (static_cast<int> (data_s.at(i).substr(5, 1).at(0) - 48));
        char Symbol = static_cast<int> (data_s.at(i).substr(1, 1).at(0));

        if (Cha_Ctrl == "C")
        {
            Controller* contr_ptr = new ConsoleController();
            Character* p = new Character(Symbol, contr_ptr, Strength, Stamina);
            Position pos;
            pos.Reihe = Reihe;
            pos.Spalte = Spalte;
            this->place(pos, p);
            return p;

        }
        else if (Cha_Ctrl == "S")
        {
            Controller* contr_ptr = new StationaryController();
            Character* p = new Character(Symbol, contr_ptr, Strength, Stamina);
            Position pos;
            pos.Reihe = Reihe;
            pos.Spalte = Spalte;
            this->place(pos, p);
            return p;
        }

    }

    if (strncmp(&t, "D", 1) == 0)
    {
        int Door_Reihe = static_cast<int> ((data_s.at(i).substr(1, 1).at(0) - 48))*10 + (static_cast<int> (data_s.at(i).substr(2, 1).at(0) - 48));
        int Active_Spalte = static_cast<int> ((data_s.at(i).substr(8, 1).at(0) - 48))*10 + (static_cast<int> (data_s.at(i).substr(9, 1).at(0) - 48));
        int Active_Reihe = static_cast<int> ((data_s.at(i).substr(6, 1).at(0) - 48))*10 + (static_cast<int> (data_s.at(i).substr(7, 1).at(0) - 48));
        int Door_Spalte = static_cast<int> ((data_s.at(i).substr(3, 1).at(0) - 48))*10 + (static_cast<int> (data_s.at(i).substr(4, 1).at(0) - 48));
        char ID = static_cast<char> (data_s.at(i).substr(5, 1).at(0));
        if (ID == 'S')
        {
            m_map[Door_Reihe][Door_Spalte] = new Door(nullptr);
            Tile* door_ptr = m_map[Door_Reihe][Door_Spalte];
            Passive* passive_ptr = static_cast<Passive*> (door_ptr);
            m_map[Active_Reihe][Active_Spalte] = new Switch(nullptr, passive_ptr);
            return nullptr;
        }
        else if (ID == 'L')
        {

            m_map[Door_Reihe][Door_Spalte] = new Door(nullptr);
            Tile* door_ptr = m_map[Door_Reihe][Door_Spalte];
            Passive* passive_ptr = static_cast<Passive*> (door_ptr);
            m_map[Active_Reihe][Active_Spalte] = new Lever(nullptr, passive_ptr);
            return nullptr;
        }

    }

    if (strncmp(&t, "T", 1) == 0)
    {
        int T_Reihe = static_cast<int> ((data_s.at(i).substr(1, 1).at(0) - 48))*10 + (static_cast<int> (data_s.at(i).substr(2, 1).at(0) - 48));
        int T_Spalte = static_cast<int> ((data_s.at(i).substr(3, 1).at(0) - 48))*10 + (static_cast<int> (data_s.at(i).substr(4, 1).at(0) - 48));
        m_map[T_Reihe][T_Spalte] = new Trap(nullptr);
        return nullptr;
    }

    if (strncmp(&t, "I", 1) == 0)
    {
        string i_id = data_s.at(i).substr(1, 2);
        int I_Reihe = static_cast<int> ((data_s.at(i).substr(3, 1).at(0) - 48))*10 + (static_cast<int> (data_s.at(i).substr(4, 1).at(0) - 48));
        int I_Spalte = static_cast<int> ((data_s.at(i).substr(5, 1).at(0) - 48))*10 + (static_cast<int> (data_s.at(i).substr(6, 1).at(0) - 48));
        {
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
            return nullptr;
        }

    }
    return nullptr;
}
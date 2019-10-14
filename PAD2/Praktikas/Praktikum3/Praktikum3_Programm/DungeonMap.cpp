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

#include "DungeonMap.h"
#include "Switch.h"

DungeonMap::DungeonMap(int height, int width,  Position pos)
{

    m_height = height;
    m_width = width;
    m_map = new Tile**[height];


    for (auto i = 0; i < height; i++)
    {
        m_map[i] = new Tile*[width];
        for (auto j = 0; j < width; j++)
        {
       //     m_map[i][j] = new Tile(nullptr);
        }
    }

   

}

DungeonMap::DungeonMap(int height, int width, const vector<string>& data, const vector<string>& data_s, Position pos)
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
    for (int i = 0; i < data_s.size(); i++)
    {
        int Door_Reihe, Switch_Reihe, Door_Spalte, Switch_Spalte;

        Door_Reihe = static_cast<int> (data_s.at(i).at(0)) - 48;
        Door_Spalte = static_cast<int> (data_s.at(i).at(1)) - 48;
        Switch_Reihe = static_cast<int> (data_s.at(i).at(2)) - 48;
        Switch_Spalte = static_cast<int> (data_s.at(i).at(3)) - 48;

        //m_map[Door_Reihe][Door_Spalte] = new Door(nullptr);
        //Door* door_ptr = m_map[Door_Reihe][Door_Spalte];
        //Passive* passive_ptr = static_cast<Passive*> (door_ptr);
        Door* door_ptr = new Door(nullptr);
        m_map[Door_Reihe][Door_Spalte] = door_ptr;

        m_map[Switch_Reihe][Switch_Spalte] = new Switch(nullptr, door_ptr);

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

//    m_map = nullptr;
//    m_height = 0;
//    m_width = 0;
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

void DungeonMap::place(Position pos, Character* c)
{
    m_map[pos.Reihe][pos.Spalte]->SetFigur(c);
}

void DungeonMap::print() const
{
    for (auto i = 0; i < m_height; i++)
    {
        for (auto j = 0; j < m_width; j++)
        {
                 
            m_map[i][j]->print();

        }
        cout << endl;

    }
    cout << endl << endl;
}

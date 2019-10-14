/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameEngine.cpp
 * Author: stud
 * 
 * Created on 29. April 2017, 10:50
 */

#include "GameEngine.h"

GameEngine::GameEngine(int height, int width, const vector<string>& data, const vector<string>& data_s, Position pos)
: m_feld(DungeonMap(height, width, data, data_s, pos))
{
    ConsoleController* contr_ptr = new ConsoleController();
    Character* p = new Character('M', contr_ptr);

    m_figuren.push_back(p);
    m_feld.place(pos, p);
}

GameEngine::~GameEngine()
{
    for (int i = 0; i < m_figuren.size(); i++)
    {
        delete m_figuren.at(i);

    }

}

bool GameEngine::finished() const
{

    return false;
}

void GameEngine::turn()
{

    Position pos;
    try
    {
        pos = m_feld.findCharacter(m_figuren.at(0));
    }
    catch (const invalid_argument& e)
    {
        cerr << "Error: " << e.what() << "/n";
    }
    Tile* tmpTile;
    try
    {
        tmpTile = m_feld.findTile(pos);
    }

    catch (const out_of_range& ie)
    {
        cerr << "Error: " << ie.what() << "/n";
    }




    switch (m_figuren.at(0)->move())
    {
    case 1:
        pos.Reihe++;
        pos.Spalte--;
        break;
    case 2:
        pos.Reihe++;
        break;
    case 3:
        pos.Reihe++;
        pos.Spalte++;
        break;
    case 4:
        pos.Spalte--;
        break;
    case 5:
        break;
    case 6:
        pos.Spalte++;
        break;
    case 7:
        pos.Reihe--;
        pos.Spalte--;
        break;
    case 8:
        pos.Reihe--;
        break;
    case 9:
        pos.Reihe--;
        pos.Spalte++;
        break;
    }

    Tile* newTile = m_feld.findTile(pos);
    tmpTile->onLeave(newTile);

    m_feld.print();


}

void GameEngine::run()
{

    m_feld.print();
    while (!finished())
        turn();

}

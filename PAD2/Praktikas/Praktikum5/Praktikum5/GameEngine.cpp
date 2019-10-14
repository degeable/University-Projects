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

GameEngine::GameEngine(int height, int width, const vector<string>& data, const vector<string>& data_s)
: m_feld(DungeonMap(height, width, data, data_s)), fin(false)
{

    m_figuren = m_feld.Parse(data_s);


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

    return fin;
}

void GameEngine::turn()
{
    for (int i = 0; i < m_figuren.size(); i++)
    {



        Position pos;
        try
        {
            pos = m_feld.findCharacter(m_figuren.at(i));
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




        switch (m_figuren.at(i)->move())
        {
        case 0: menue();
            return;
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
        m_figuren.at(i)->showInfo();
    

        if (m_figuren.at(i)->getHitpoints() <= 0)
        {
            cout << "Spieler gestorben..." << endl;
            m_feld.findTile(m_feld.findCharacter(m_figuren.at(i)))->SetFigur(nullptr);
            m_figuren.erase(m_figuren.begin() + i);


        }

    }
    int count = 0;
    for (int i = 0; i < m_figuren.size(); i++)
    {

        if (m_figuren.at(i)->getCon()->getID() == 'C')
            count++;
    }
    if (count == 0)
    {
        setFin(true);
        cout << "Kein Menschlicher Spieler am Leben, Spiel Beendet" << endl;
    }

    m_feld.print(m_feld.findCharacter(m_figuren.at(0)));



}

void GameEngine::run()
{

    m_feld.print(m_feld.findCharacter(m_figuren.at(0)));
    while (finished() == false)
        turn();

}

vector<Character*>& GameEngine::getFiguren()
{
    return m_figuren;
}

void GameEngine::menue()
{

    cout << "DungeonCrawler 1.3" << endl << endl;
    cout << "1. Neues Spiel (level1.txt)" << endl;
    cout << "2. SpielerInfos" << endl;
    cout << "3. Spiel Beenden" << endl;
    int b = 0;
    cin>>b;
    switch (b)
    {
    case 1: run();
        break;
    case 2:
        for (int i = 0; i < m_figuren.size(); i++)
        {
            m_figuren.at(i)->showInfo();
            cout << "\n";
        }
        menue();
        break;


    case 3: fin = true;
        break;


    }

}

void GameEngine::setFin(bool fin)
{
    this->fin = fin;
};




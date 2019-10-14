/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameEngine.h
 * Author: stud
 *
 * Created on 29. April 2017, 10:50
 */

#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <vector>
#include "DungeonMap.h"
#include "Character.h"
#include "ncurses.h"


using namespace std;

class GameEngine
{
public:
    GameEngine(int height, int width, const vector<string>&data,const vector<string>& data_s);
    virtual ~GameEngine();

    bool finished(bool b) const;
    void turn();
    void run();
    vector<Character*>& getFiguren();
    void menue();
   
private:
    DungeonMap m_feld;
    vector<Character*> m_figuren ;

};

#endif /* GAMEENGINE_H */


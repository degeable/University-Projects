/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AttackController.h
 * Author: stud
 *
 * Created on 16. Juni 2017, 13:23
 */

#ifndef ATTACKCONTROLLER_H
#define ATTACKCONTROLLER_H

#include "Controller.h"
#include "DungeonMap.h"
//#include "Position.h"

class AttackController : public Controller
{
public:
    AttackController(Character* c,DungeonMap* map,Character* z);
    AttackController(const AttackController& orig);
    int move() override;
    char getID() override;

    virtual ~AttackController();

private:
    DungeonMap* m_map;
    vector<Position>m_lastPath;
    Character* ziel;
    char id='A';
};

#endif /* ATTACKCONTROLLER_H */


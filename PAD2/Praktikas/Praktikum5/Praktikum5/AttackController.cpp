///*

/* 
 * File:   AttackController.cpp
 * Author: stud
 * 
 * Created on 16. Juni 2017, 13:23
 */

#include "AttackController.h"
#include "Active.h"

AttackController::AttackController(Character* c, DungeonMap* map, Character* z) : m_map(map), Controller(c), ziel(z)
{

}


//AttackController::AttackController(const AttackController& orig) : Controller(c)
//{
//}

AttackController::~AttackController()
{
    m_map=nullptr;
    ziel=nullptr;
    setC_figur(nullptr);
}

char AttackController::getID()
{
    return id;
}


int AttackController::move()
{

    vector<Position> newPath;
    Position foundCharacter = m_map->findCharacter(ziel); 
    Position attacker = m_map->findCharacter(this->getC_figur());
    if (foundCharacter != Position(-1, -1))
        newPath = m_map->getPathto(attacker, foundCharacter);
    if (newPath.size() != 0)
        m_lastPath = newPath;

    if (m_lastPath.size() == 0)
        return 5;
   
    Position dp = attacker- m_lastPath.at(0);
    m_lastPath.erase(m_lastPath.begin());


    if (dp.Reihe == -1 && dp.Spalte == 1){
        return 1;


    }
    else if (dp.Reihe == -1 && dp.Spalte == 0){
        return 2;
}
    else if (dp.Reihe == -1 && dp.Spalte == -1){
        return 3;
}
    else if (dp.Reihe == 0 && dp.Spalte == 1){
        return 4;
}
    else if (dp.Reihe == 0 && dp.Spalte == 0){
        return 5;
}
    else if (dp.Reihe == 0 && dp.Spalte == -1){
        return 6;
}
    else if (dp.Reihe == 1 && dp.Spalte == 1){
        return 7;
}
    else if (dp.Reihe == 1 && dp.Spalte == 0){
        return 8;
}
    else if (dp.Reihe == 1 && dp.Spalte == -1){
        return 9;
}
    else
    {
        cerr << "alter Pfad ungueltig geworden.";
        m_lastPath.clear();
        return 5;



    }
}
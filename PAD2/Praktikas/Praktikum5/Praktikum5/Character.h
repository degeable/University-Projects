/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Character.h
 * Author: stud
 *
 * Created on 29. April 2017, 09:15
 */

#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include "Controller.h"
#include "ConsoleController.h"
#include <vector>

using namespace std;
class ConsoleController;
class Item;
class StationaryController;
class Character
{
public:
    Character(char f,Controller* c,int stamina, int strength);
   ~Character();

    int move();
    char getFigur() const;
    int getmaxHP() const;
    void showInfo()const;
    void addItem(Item* it);
    int getStrength()const;
    int getStamina()const;
    void setHitpoints(int hitpoints);
    int getHitpoints() const;
    void setCon(Controller* con);
    Controller* getCon() const;
private:
    char m_figur;
   Controller* m_con;
    int m_stamina;
    int m_strength;
    int m_hitpoints;
    vector<Item*>m_inventory;
    int HP;
};

#endif /* CHARACTER_H */


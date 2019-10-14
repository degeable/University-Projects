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
using namespace std;
class ConsoleController;
class Character
{
public:
    Character(char f, ConsoleController* c);
    int move();
    char getFigur() const;
private:
    char m_figur;
    ConsoleController* m_con;

};

#endif /* CHARACTER_H */


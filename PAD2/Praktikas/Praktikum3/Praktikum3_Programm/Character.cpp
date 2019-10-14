/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Character.cpp
 * Author: stud
 * 
 * Created on 29. April 2017, 09:15
 */

#include "Character.h"

Character::Character(char f, ConsoleController* c) : m_figur(f),m_con(c)
{
    c->setC_figur(this);
}

char Character::getFigur() const
{
    return m_figur;
}

int Character::move()
{
    return m_con->move();
}



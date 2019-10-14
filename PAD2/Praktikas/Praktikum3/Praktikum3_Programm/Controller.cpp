/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Controller.cpp
 * Author: stud
 * 
 * Created on 5. Mai 2017, 08:16
 */

#include "Controller.h"

Controller::Controller()
{
}

void Controller::setC_figur(Character* c_figur)
{
    this->c_figur = c_figur;
}

Character* Controller::getC_figur() const
{
    return c_figur;
}

Controller::Controller(const Controller& orig)
{
}

Controller::~Controller()
{
}


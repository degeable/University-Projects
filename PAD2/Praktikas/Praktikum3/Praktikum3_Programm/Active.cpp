/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Active.cpp
 * Author: stud
 * 
 * Created on 5. Mai 2017, 07:34
 */

#include "Active.h"

Active::Active(Character* c) : Tile(c)//,a_slave(Passive* slave)
{
    a_status = false;
}

Active::~Active()
{
}

void Active::SetA_slave(Passive* a_slave)
{

    this->a_slave = a_slave;
}

void Active::SetA_status(bool a_status)
{
    this->a_status = a_status;
}

bool Active::IsA_status() const
{
    return a_status;
}

Passive* Active::GetA_slave() const
{
    return a_slave;
}



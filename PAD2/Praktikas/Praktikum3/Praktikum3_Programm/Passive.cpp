/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Passive.cpp
 * Author: stud
 * 
 * Created on 5. Mai 2017, 07:34
 */

#include "Passive.h"

Passive::Passive(Character* c) : Tile(c)
{
    p_Status=false;
}

Passive::~Passive()
{
}

void Passive::SetStatus(bool Status)
{
    this->p_Status = Status;
}

bool Passive::IsStatus() const
{
    return p_Status;
}


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Switch.cpp
 * Author: stud
 * 
 * Created on 5. Mai 2017, 07:54
 */

#include "Switch.h"

Switch::Switch(Character* c, Passive* p) : Active(c)
{
    SetA_slave(p);
}

Switch::~Switch()
{
}

bool Switch::IsA_status() const
{
    return Active::IsA_status();
}

void Switch::SetA_slave(Passive* a_slave)
{
    Active::SetA_slave(a_slave);
}

void Switch::SetA_status(bool a_status)
{
    Active::SetA_status(a_status);
}

void Switch::print()
{
    if (this->hasCharacter())
    {
        cout << this->GetFigur()->getFigur();
    }
    else if (IsA_status())
    {
        cout << "!";
    }
    else
        cout << "?";
}

void Switch::onEnter(Character* c, Tile* fromTile)
{
  this->SetA_status(true);
  this->SetFigur(c);
   this->GetA_slave()->SetStatus(true);  //Funktionsname vielleicht etwas unglücklich 
}

void Switch::onLeave(Tile* toTile)
{
    if (toTile->hasCharacter() == false)
    {
        toTile->onEnter(Active::GetFigur(), this);
       this->SetFigur(nullptr);
    }
}

bool Switch::istBetretbar() const
{
    return true;
}

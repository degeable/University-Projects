/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lever.cpp
 * Author: stud
 * 
 * Created on 19. Mai 2017, 17:13
 */

#include "Lever.h"

Lever::Lever(Character* c, Passive* p) : Active(c)
{
    this->SetA_slave(p);
}

Lever::~Lever()
{
}

bool Lever::IsA_status() const
{
    return Active::IsA_status();
}

void Lever::SetA_slave(Passive* a_slave)
{
    Active::SetA_slave(a_slave);
}

void Lever::SetA_status(bool a_status)
{
    Active::SetA_status(a_status);
}

void Lever::print() 
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

void Lever::onEnter(Character* c, Tile* fromTile)
{this->SetFigur(c);
if(IsA_status()==false){
  this->SetA_status(true);
   this->GetA_slave()->SetStatus(true);//Funktionsname vielleicht etwas unglücklich 
}
else {this->SetA_status(false);
   this->GetA_slave()->SetStatus(false);}
}

void Lever::onLeave(Tile* toTile)
{
    if (toTile->hasCharacter() == false)
    {
        toTile->onEnter(Active::GetFigur(), this);
       this->SetFigur(nullptr);
    }
}

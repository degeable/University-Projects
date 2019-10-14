/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Door.cpp
 * Author: stud
 * 
 * Created on 5. Mai 2017, 07:57
 */

#include "Door.h"

Door::Door(Character* c) : Passive(c)
{
    SetStatus(false);

}

Door::~Door()
{
}

bool Door::IsStatus() const
{
    return Passive::IsStatus();
}

void Door::SetStatus(bool Status)
{
    Passive::SetStatus(Status);

}

void Door::onEnter(Character* c, Tile* fromTile)
{
    if(this->IsStatus()){
        this->SetFigur(c);
    }else{
        fromTile->onEnter(c,this);
    }
}

void Door::onLeave(Tile* toTile)
{
    if(!toTile->hasCharacter()){
        Character* c=this->GetFigur();
      this->SetFigur(nullptr);
      
         toTile->onEnter(c,this);
           ;
         }
}

bool Door::isTransparent() const
{
    return IsStatus();
}


void Door::print() 
{
    if (this->hasCharacter())
    {
        cout <<this->GetFigur()->getFigur();
    }
    else if (IsStatus())
    {
        cout << "/";
    }
    else
        cout << "X";
}

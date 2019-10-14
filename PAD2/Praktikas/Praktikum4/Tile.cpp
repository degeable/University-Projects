/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tile.cpp
 * Author: stud
 * 
 * Created on 25. April 2017, 13:00
 */

#include "Tile.h"
#include "Floor.h"

Tile::Tile(Character* c)
{
    figur = c;
 
}

Tile::~Tile()
{

}

void Tile::SetFigur(Character* figur)
{
    this->figur = figur;
}

Character* Tile::GetFigur() const
{
    return figur;
}

bool Tile::hasCharacter() const
{
    if (figur == nullptr)
    {
        return false;
    }
    else
        return true;
}

void Tile::onLeave(Tile* toTile)
{
    if (toTile->hasCharacter() == false)
    {
        toTile->onEnter(figur, this);
        figur = nullptr;
    }
}

void Tile::onEnter(Character* c, Tile* fromTile)
{
    figur = c;
}

void Tile::print()
{

}

bool Tile::isTransparent() const
{
    return true;
}

void Tile::setItem(Item* i)
{
   item=i;
}


Item* Tile::GetItem() 
{
    return item;
}




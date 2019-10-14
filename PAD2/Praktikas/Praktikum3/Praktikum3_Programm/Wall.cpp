/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Wall.cpp
 * Author: stud
 * 
 * Created on 3. Mai 2017, 21:01
 */

#include "Wall.h"
#include "Tile.h"

Wall::Wall(Character* c) : Tile(c)
{

}

Wall::~Wall()
{
}

void Wall::onEnter(Character* c, Tile* fromTile)
{

    this->onLeave(fromTile, c);

}

void Wall::onLeave(Tile* toTile, Character* c)
{
    toTile->onEnter(c, this);

}

void Wall::print() const
{
    if (hasCharacter())
    {
        cout << this->GetFigur()->getFigur();
    }
    else
        cout << "#";
}


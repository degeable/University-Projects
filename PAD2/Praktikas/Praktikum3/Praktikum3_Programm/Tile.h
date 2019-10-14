/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tile.h
 * Author: stud
 *
 * Created on 25. April 2017, 13:00
 */

#ifndef TILE_H
#define TILE_H
#include <iostream>
#include "Character.h"

using namespace std;

class Tile
{
public:

    Tile(Character* c);
    virtual ~Tile();

    void SetFigur(Character* figur);
    Character* GetFigur() const;
    bool hasCharacter() const;
    virtual void onLeave(Tile* toTile);
    virtual void onEnter(Character* c, Tile* fromTile);
    virtual void print()const=0;
   


private:


    Character* figur = nullptr;

};

#endif /* TILE_H */


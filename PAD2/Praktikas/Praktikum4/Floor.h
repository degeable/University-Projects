/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Floor.h
 * Author: stud
 *
 * Created on 3. Mai 2017, 21:00
 */

#ifndef FLOOR_H
#define FLOOR_H
#include "Character.h"
#include "Tile.h"

class Floor : public Tile
{
public:
    Floor(Character* c);
    virtual ~Floor();
    virtual void onEnter(Character* c, Tile* fromTile) override;
    virtual void onLeave(Tile* toTile) override;
    virtual void print() override;
 void setItem(Item* i) override;
 bool hasItem();


private:
  
};

#endif /* FLOOR_H */


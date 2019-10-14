/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Wall.h
 * Author: stud
 *
 * Created on 3. Mai 2017, 21:01
 */

#ifndef WALL_H
#define WALL_H
#include "Character.h"
#include "Tile.h"
class Wall : public Tile
{
public:
    
    Wall(Character* c);
    virtual ~Wall();
  virtual void onEnter(Character* c, Tile* fromTile) override;
  virtual void onLeave(Tile* toTile,Character* c) ;
  virtual void print() override;
    bool isTransparent()const override;

private:

};

#endif /* WALL_H */


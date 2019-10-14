/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Trap.h
 * Author: stud
 *
 * Created on 19. Mai 2017, 17:48
 */

#ifndef TRAP_H
#define TRAP_H
#include "Tile.h"

class Trap :public Tile 
{
public:
    Trap(Character* c);

    virtual ~Trap();

    void onEnter(Character* c, Tile* fromTile) override;
    void onLeave(Tile* toTile) override;
    void print() override;
    bool istBetretbar() const override;


private:
   bool t_active;
};

#endif /* TRAP_H */


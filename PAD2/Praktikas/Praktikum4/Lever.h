/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lever.h
 * Author: stud
 *
 * Created on 19. Mai 2017, 17:13
 */

#ifndef LEVER_H
#define LEVER_H
#include "Active.h"
class Lever : public Active
{
public:
    Lever(Character* c,Passive* p);

    virtual ~Lever();
    bool IsA_status() const override;
    void SetA_slave(Passive* a_slave) override;
    void SetA_status(bool a_status) override; 
    void print()override;
    void onEnter(Character* c, Tile* fromTile) override;
    void onLeave(Tile* toTile) override;


private:

};


#endif /* LEVER_H */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Switch.h
 * Author: stud
 *
 * Created on 5. Mai 2017, 07:54
 */

#ifndef SWITCH_H
#define SWITCH_H

#include "Active.h"
#include "Door.h"


class Switch : public Active
{
public:
    Switch(Character* c,Passive* p);

    virtual ~Switch();
    bool IsA_status() const override;
    void SetA_slave(Passive* a_slave) override;
    void SetA_status(bool a_status) override; 
    void print()override;
    void onEnter(Character* c, Tile* fromTile) override;
    void onLeave(Tile* toTile) override;
    bool istBetretbar() const override;


private:

};

#endif /* SWITCH_H */


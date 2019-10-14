/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Door.h
 * Author: stud
 *
 * Created on 5. Mai 2017, 07:57
 */

#ifndef DOOR_H
#define DOOR_H

#include "Passive.h"


class Door : public Passive
{
public:
    Door(Character* c);
 
    virtual ~Door();
    bool IsStatus() const override;
    void SetStatus(bool Status) override;
    void print() override;
    void onEnter(Character* c, Tile* fromTile) override;
    void onLeave(Tile* toTile) override;
    bool isTransparent() const override;
    bool istBetretbar() const override;




private:

};

#endif /* DOOR_H */


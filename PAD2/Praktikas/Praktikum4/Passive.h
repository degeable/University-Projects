/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Passive.h
 * Author: stud
 *
 * Created on 5. Mai 2017, 07:34
 */

#ifndef PASSIVE_H
#define PASSIVE_H

#include "Tile.h"


class Passive : public Tile
{
public:
    Passive(Character* c);

    virtual ~Passive();
   virtual void SetStatus(bool Status)=0;
   virtual bool IsStatus()const=0;
private:
    bool p_Status;
};

#endif /* PASSIVE_H */


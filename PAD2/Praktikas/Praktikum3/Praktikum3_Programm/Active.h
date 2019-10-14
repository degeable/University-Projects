/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Active.h
 * Author: stud
 *
 * Created on 5. Mai 2017, 07:34
 */

#ifndef ACTIVE_H
#define ACTIVE_H


#include "Tile.h"
#include "Passive.h"

class Active : public Tile
{
public:
    Active(Character*);

    virtual ~Active();
    virtual void SetA_slave(Passive* a_slave) = 0;
    virtual void SetA_status(bool a_status) = 0;
    virtual bool IsA_status() const = 0;


    Passive* GetA_slave() const;
private:
    bool a_status;
    Passive* a_slave;
};

#endif /* ACTIVE_H */


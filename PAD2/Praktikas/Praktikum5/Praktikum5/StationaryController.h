/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StationaryController.h
 * Author: stud
 *
 * Created on 19. Mai 2017, 18:05
 */

#ifndef STATIONARYCONTROLLER_H
#define STATIONARYCONTROLLER_H

#include "Controller.h"
#include "Character.h"

class StationaryController : public Controller
{
public:
    StationaryController(Character* c);

    virtual ~StationaryController();
     int move() override;
  char getID() override;

private:
char id='S';
};

#endif /* STATIONARYCONTROLLER_H */


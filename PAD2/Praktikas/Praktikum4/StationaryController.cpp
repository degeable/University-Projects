/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StationaryController.cpp
 * Author: stud
 * 
 * Created on 19. Mai 2017, 18:05
 */

#include "StationaryController.h"

StationaryController::StationaryController()
{
}



StationaryController::~StationaryController()
{
}

int StationaryController::move()
{
    return (rand()%9)+1;
}

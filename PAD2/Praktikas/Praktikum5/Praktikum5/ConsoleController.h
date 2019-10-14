/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConsoleController.h
 * Author: stud
 *
 * Created on 5. Mai 2017, 08:20
 */

#ifndef CONSOLECONTROLLER_H
#define CONSOLECONTROLLER_H

#include "Controller.h"
#include "Character.h"

class ConsoleController : public Controller
{
public:
    ConsoleController(Character* c);
    int move()override;
    virtual ~ConsoleController();
    char getID() override;

  
private:
 char id='C';
 
};

#endif /* CONSOLECONTROLLER_H */


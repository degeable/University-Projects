/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConsoleController.cpp
 * Author: stud
 * 
 * Created on 5. Mai 2017, 08:20
 */

#include "ConsoleController.h"

ConsoleController::ConsoleController()
{
}

ConsoleController::~ConsoleController()
{
}

int ConsoleController::move()
{
    int m;
    cout << "In welche Richtungs solls gehen? (1-9)" << endl;
    cin>>m;
    if (!cin)
    {
        cin.clear();
        cin.ignore();
    }
    return m;
}

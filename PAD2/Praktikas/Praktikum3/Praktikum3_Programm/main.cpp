/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: stud
 *
 * Created on 25. April 2017, 12:50
 */

#include <cstdlib>

#include "GameEngine.h"

int main()
{

    vector<string> level1{
        "##########",
        "####.....#",
        "###......#",
        "##########",
        "#.....#..#",
        "#...######",
        "###......#",
        "#........#",
        "#........#",
        "##########",};
    const vector<string>& Türen{
        "3452",
        "5374",}; //REIHE;SPALTE für door REIHE;SPALTE für Switch...{"DDSS"}...





    Position pos; //Startposition der Figur
    pos.Reihe = 7;
    pos.Spalte = 5;
    GameEngine ge1(10, 10, level1, Türen, pos);
    ge1.run();



    return 0;

}


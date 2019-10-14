/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mastermind.cpp
 * Author: stud
 * 
 * Created on 28. November 2017, 15:08
 */

#include "Mastermind.h"
#include <iostream>
using namespace std;

vector<int>gu;
vector<int>lös;
int length;

Mastermind::Mastermind()
{

}

Mastermind::Mastermind(const Mastermind& orig)
{
}

Mastermind::~Mastermind()
{
}

int Mastermind::start()
{
    int lösung=0;  //int variable für die Lösung
    cout << "Geben sie ihre Lösung ein:(1-6)" << endl;

    do
    {
        cin>>lösung;
        lös.push_back(lösung);
    }
    while (lös.size() != 4); //4 als feste länge
    
    length=lös.size(); //eigentlich unnötig siehe zeile 45...
    if (!isValidInput(lös, length, 1, 6))
    {
        cout << "Falsche eingabe!";
        return 0;
    }

    cout << endl << endl << endl; //nur zur Optik

    return 1;



}

int Mastermind::guess()
{
    int bl = 0;  //variablevfür black
    int wh = 0;  //...
    int lösung;
    cout << "Guess:" << endl;  //guess eingeben mit do while schleife

    do
    {
        cin>>lösung;
        gu.push_back(lösung);
    }
    while (gu.size() != 4);  //nur 4 zahlen


    if (!isValidInput(gu, length, 1, 6))  //eingabe prüfen
    {
        cout << "Falsche eingabe!" << endl;
        gu.clear(); //vector clearen für mächste runde....
        return 0;
    }

    bl = black(lös, gu);  //prüfen vie viel black und white
    wh = white(lös, gu);

    cout << "Guess...Black....White" << endl;

    for (auto elem : gu)
    {
        cout << elem; //guess zahlen ausgeben
    }

    cout << "    " << bl << "        " << wh << endl;  //Platzhalter der übersicht halber

    if (bl == length)  //wenn alle richtig sind finish
    {
        cout << "Spiel vorbei!" << endl;
        return 2;   //return 2 damit spiel beendet wird
    }
    gu.clear();

    return 0;
}

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
#include <iostream>
#include <string>
#include <fstream>
#include "GameEngine.h"
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    ifstream a;
    a.open("level1.txt");
    string s;
    vector<string>map;
    vector<string>data;
    int Reihe, Spalte;
    a >> Reihe>>Spalte;

    for (int i = 1; i <= Reihe; i++)
    {
        getline(a, s);
        
        if (s != "")
        {
            map.push_back(s);
        }
        else
            i--;

    }
        do{
            getline(a,s);
            
            if(s!="")
            data.push_back(s);
        }while(a.good());
        
    a.close();
//     
    //
    //    vector<string> level1{
    //        "####################",
    //        "#..................#",
    //        "#..................#",
    //        "#..................#",
    //        "#..................#",
    //        "#..................#",
    //        "#..................#",
    //        "#..................#",
    //        "#..................#",
    //        "#..................#",
    //        "#..................#",
    //        "#..................#",
    //        "#......#####.......#",
    //        "#..................#",
    //        "#..................#",
    //        "#..................#",
    //        "#..................#",
    //        "#..................#",
    //        "#..................#",
    //        "####################",};
    //        /*Syntax für data_s:
    //         * stelle 0 ID für tile obj. C für Character D für Door....
    //         * ... todo
    //         */
    //        const vector<string>& data_s{
    //            "C@10100705C",
    //            "C%05050305S",
    //            "D0303L0503",
    //            "D0404S0505",
    //            "T0408",
    //            "T0304",
    //            "T0306",
    //            "T0407",
    //            "IMA0111",
    //            "IAS0113",};
    //
    //
    //
    //
    //
    //
          GameEngine ge1(Reihe, Spalte, map, data);
            ge1.menue();
    


    return 0;
}


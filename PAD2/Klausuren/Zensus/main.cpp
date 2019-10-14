/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: stud
 *
 * Created on 8. Juli 2017, 14:49
 */

#include <cstdlib>
#include  <iostream>
#include "Country.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv)
{
    Country c("zensus-utf8.txt");
//    Country c("leer.txt");
    int x;
        string stadt;

    cout<<"Menu:"<<endl;
    cout<<"1. Bundesländer"<<endl;
    cout<<"2. Städte"<<endl;
    cout<<"3. Suchen"<<endl;
    cout<<"4. Doppelte anzeigen"<<endl;
    cout<<"5. gesamt pop bundesland muschi"<<endl;
    cin>>x;
    switch(x){
    case 1: c.printLand();
    break;
    case 2: c.printTown();
    break;
    case 3: cout<<"Name?"<<endl;
    cin>>stadt;  
    c.sucheStadt(stadt);
    break;
    case 4:
        
        c.doppelte();
    break;
    case 5:
        c.gesamt();
        break;
    case 6: 
        c.letzte();
        break;
    }
    
            
            
//    c.printLand();
//    c.printTown();

    return 0;
}


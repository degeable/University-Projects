/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: stud
 *
 * Created on 21. November 2017, 19:43
 */

#include <cstdlib>

#include "Mastermind.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv)
{
    int finish=0;
    int counter=0;
    Mastermind mind;
   if(mind.start()==1)
   {
       while(finish!=2 && counter<8) //finish bei 2 // counter darf nur 8 werden
          finish=mind.guess();
          counter++;
   }

    return 0;
    
}


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: stud
 *
 * Created on 10. Juli 2017, 11:19
 */

#include <cstdlib>
#include "Wetterdienst.h"
#include <string>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv)
{
  Wetterdienst w("Frankfurt-nb.txt", "Hamburg-nb.txt");
//  w.Aufgabe4a();
 // w.Aufgabe4b();
  w.Aufgabe4c();
 // w.Aufgabe4d();
  //w.Aufgabe4e();
    return 0;
}


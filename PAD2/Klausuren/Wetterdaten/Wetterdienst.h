/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Wetterdienst.h
 * Author: stud
 *
 * Created on 10. Juli 2017, 12:20
 */

#ifndef WETTERDIENST_H
#define WETTERDIENST_H
#include <string>
#include <fstream>
#include "Messung.h"
#include <map>
#include <list>
#include <iostream>
#include <vector>
#include <set>
#include "Zeitpunkt.h"
#include <fstream>
class Wetterdienst
{
public:
    Wetterdienst(const std::string& datei1,const std::string& datei2);
//    Wetterdienst(const Wetterdienst& orig);
    virtual ~Wetterdienst();
    
    void Aufgabe4a();
    void Aufgabe4b();
    void Aufgabe4c();
    void Aufgabe4d();
    void Aufgabe4e();
    
private:
    std::vector<Messung>ffmvec;
    std::vector<Messung>hhvec;
    std::map<Zeitpunkt,Messung>ffmmap;
    std::map<Zeitpunkt,Messung>hhmmap;

};

#endif /* WETTERDIENST_H */


/* 
 * File:   lied.h
 * Author: fs
 *
 * Created on 24. November 2016, 17:19
 */
#ifndef LIED_H
#define	LIED_H
#include <vector>
#include <string>
#include "DynArray.h"
#include <iostream>
using namespace std;

class DynArray;

class lied {
public:
    lied();
    void setNew(string titel, string interpret, string jahr, string laenge, string Genre);
    void showDetails();
    void setTitel();
    void setInterpret();
    void setErscheinungsjahr();
    void setLaenge();
    void setGenre();
    string getTitel();
    void printTitel(DynArray &song);
private:
enum Genre {
    Rock, Pop, Klassik, HardRock, Techno, HipHop, Jazz, none
};
    string Titel;
    string Interpret;
    string Erscheinungsjahr;
    string Laenge;
    Genre genre;
};

/* LIED_H */

#endif
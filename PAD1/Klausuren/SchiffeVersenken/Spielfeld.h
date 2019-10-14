/* 
 * File:   Spielfeld.h
 * Author: fs
 *
 * Created on 4. Februar 2017, 10:59
 */

#ifndef SPIELFELD_H
#define	SPIELFELD_H
#include <vector>
#include "Schiff.h"
using namespace std;

class Spielfeld {
public:
    Spielfeld();
    Spielfeld(const Spielfeld& orig);
    virtual ~Spielfeld();
    void Ausgeben();
    void Spielen();
    bool fertig(int reihe,int spalte);
private:
    vector<Schiff>m_schiffe;
    char Leinwand[11][11];
};

#endif	/* SPIELFELD_H */


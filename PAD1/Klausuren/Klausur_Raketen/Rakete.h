/* 
 * File:   Rakete.h
 * Author: fs
 *
 * Created on 10. Januar 2017, 14:22
 */

#ifndef RAKETE_H
#define	RAKETE_H
#include <vector>
#include <string>
#include "Tank.h"
#include "Triebwerke.h"

using namespace std;

class Rakete {
public:
    Rakete();
    Rakete(const Rakete& orig);
    virtual ~Rakete();
    void einfuegen(Triebwerke t);
    void einfuegen(Tank ta, int index, int voll);
    double berechneGewicht();
    double berechneTWR();
    double berechneBrenndauer();
    void print();
private:
    vector<Tank>tank;
    vector<Triebwerke>triebwerk;

};

#endif	/* RAKETE_H */


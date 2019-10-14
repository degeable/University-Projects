/* 
 * File:   Rakete.cpp
 * Author: fs
 * 
 * Created on 10. Januar 2017, 14:22
 */

#include "Rakete.h"
#include "Triebwerke.h"
#include "Tank.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

Rakete::Rakete() {
}

Rakete::Rakete(const Rakete& orig) {
}

Rakete::~Rakete() {
}

void Rakete::einfuegen(Triebwerke t) {
    triebwerk.push_back(t);

}

void Rakete::einfuegen(Tank tk, int index, int voll) {
    tank.push_back(tk);
    tank.at(index).setFuellstand(tk, voll);

}

double Rakete::berechneGewicht() {
    double gesamt;
    double tgesamt;
    for (auto i = 0; i < triebwerk.size(); i++) {
        gesamt += triebwerk.at(i).getGewicht();
    }
    for (auto j = 0; j < tank.size(); j++) {
        tgesamt += tank.at(j).getLeergewicht();
        tgesamt += tank.at(j).getFuellstand();
    }
    return gesamt + tgesamt;
}

double Rakete::berechneTWR() {
    double twr;

    for (auto i = 0; i < triebwerk.size(); i++) {
        twr += triebwerk.at(i).getSchub();
    }
    twr = twr / (berechneGewicht()*9.807);
    return twr;
}

double Rakete::berechneBrenndauer() {
    double stand;
    double verbrauch;

    for (auto i = 0; i < tank.size(); i++) {
        stand += tank.at(i).getFuellstand();
    }
    for (auto j = 0; j < triebwerk.size(); j++) {
        verbrauch += triebwerk.at(j).getVerbrauch();
    }
    return stand / verbrauch;
}

void Rakete::print() {
    if (tank.size() != 0 || triebwerk.size() != 0) {

        cout << "Gesamtgewicht: " << berechneGewicht() << "Kg" << endl;
        cout << "TWR: " << berechneTWR() << endl;
        cout << "Brenndauer: " << berechneBrenndauer() << "s" << endl << endl;
        for (auto i = 0; i < tank.size(); i++) {
            cout << "Tank " << i << ": " << tank.at(i).getName() << " ->Fuellmenge: " << tank.at(i).getFuellstand()/tank.at(i).getVolumen()*100 << "%" << endl;
            cout << "Art: " << tank.at(i).getArt() << endl;
            cout << "Leergewicht: " << tank.at(i).getLeergewicht() << "Kg" << endl;
            cout << "Volumen: " << tank.at(i).getVolumen() << endl;
            cout << "Gesamtgewicht: " << tank.at(i).getGesamtgewicht() << "Kg" << endl << endl;

        }
        for (auto j = 0; j < triebwerk.size(); j++) {
            cout<<"Triebwerk "<<j<<":";
            triebwerk.at(j).print();
              cout      <<endl;
        }
    }

}
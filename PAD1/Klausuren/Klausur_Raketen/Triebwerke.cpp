/* 
 * File:   Triebwerke.cpp
 * Author: fs
 * 
 * Created on 10. Januar 2017, 12:30
 */

#include "Triebwerke.h"
#include <string>
#include <iostream>

using namespace std;

Triebwerke::Triebwerke() {

}

void Triebwerke::print() {
    cout << "Name: " << name << endl;
    cout << "Gewicht: " << gewicht << "Kg" << endl;
    cout << "Schub: " << schub << "Kn" << endl;
    cout << "Verbrauch: " << verbrauch << "kg/s" << endl << endl;
}

double Triebwerke::getGewicht() const {
    return gewicht;
}

double Triebwerke::getSchub() const {
    return schub;
}

double Triebwerke::getVerbrauch() const {
    return verbrauch;
}

string Triebwerke::getName() const {
    return name;
}

Triebwerke::Triebwerke(string Name, double Schub, double Verbrauch, double Gewicht) {
    name = Name;
    gewicht = Gewicht;
    schub = Schub;
    verbrauch = Verbrauch;


}

Triebwerke::~Triebwerke() {
}


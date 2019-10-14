/* 
 * File:   Tank.cpp
 * Author: fs
 * 
 * Created on 10. Januar 2017, 13:06
 */

#include "Tank.h"
#include <string>
#include <iostream>

Tank::Tank() {
}

Tank::Tank(string Name, double Leergewicht, string Art, double Volumen, double Fuellstand, double Gesamtgewicht) {
    name = Name;
    if (Art == "TREIBSTOFF")
        art = TREIBSTOFF;
    if (Art == "NUTZLAST")
        art = NUTZLAST;
    leergewicht = Leergewicht;
    volumen = Volumen;
    fuellstand = Fuellstand;
    gesamtgewicht = Gesamtgewicht;
}

Tank::~Tank() {
}

void Tank::print2() {
    cout << "Tank: " << name << endl;
}

void Tank::print(const Tank& t) {
    cout << "Name: " << t.name << endl;
    if (t.art == 0)
        cout << "Art: Treibstoff" << endl;
    if (t.art == 1)
        cout << "Art: Nutzlast" << endl;
    cout << "Leergewicht: " << t.leergewicht << "Kg" << endl;
    cout << "Volumen: " << t.volumen << endl;
    cout << "Füllstand: " << t.fuellstand << "%" << endl;
    cout << "Gesamtgewicht: " << t.gesamtgewicht << "Kg" << endl << endl;

}

double Tank::getGesamtgewicht() const {
    return gesamtgewicht;
}

void Tank::setFuellstand(Tank tk, int fuell) {
    this->fuellstand = volumen * fuell / 100;
    cout << "Füllstand ist jetzt:" << fuellstand << "kg" << endl;
    setGesamtgewicht(fuellstand);
}

double Tank::getFuellstand() const {
    return fuellstand;
}

string Tank::getName() const {
    return name;
}

double Tank::getVolumen() const {
    return volumen;
}

double Tank::getLeergewicht() const {
    return leergewicht;
}

string Tank::getArt() const {
    if (art == 0)
        return "Treibstoff";
    else return "Nutzlast";
}

void Tank::setGesamtgewicht(double gesamtgewicht) {
    this->gesamtgewicht += gesamtgewicht;
}



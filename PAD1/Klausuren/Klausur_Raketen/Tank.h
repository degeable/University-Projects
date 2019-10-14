/* 
 * File:   Tank.h
 * Author: fs
 *
 * Created on 10. Januar 2017, 13:06
 */

#ifndef TANK_H
#define	TANK_H
#include <string>
using namespace std;

class Tank {   
public:

    enum art {
        TREIBSTOFF, NUTZLAST
    };
    Tank();
    Tank(string Name, double Leergewicht, string Art, double Volumen, double Fuellstand, double Gesamtgewicht);
    virtual ~Tank();
    void print(Tank const &t);
    void print2();
    double getGesamtgewicht() const;
    void setFuellstand(Tank tk, int fuell);
    double getFuellstand() const;
    string getName() const;
    double getVolumen() const;
    double getLeergewicht() const;
    string getArt() const;
    void setGesamtgewicht(double gesamtgewicht);

private:

    string name;
    art art;
    double leergewicht;
    double volumen;
    double fuellstand;
    double gesamtgewicht;

};

#endif	/* TANK_H */


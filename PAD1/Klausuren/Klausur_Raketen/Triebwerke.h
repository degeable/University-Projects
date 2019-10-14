/* 
 * File:   Triebwerke.h
 * Author: fs
 *
 * Created on 10. Januar 2017, 12:30
 */

#ifndef TRIEBWERKE_H
#define	TRIEBWERKE_H
#include <string>
using namespace std;

class Triebwerke {
public:
    Triebwerke();
    Triebwerke(string Name, double Schub, double Verbrauch, double Gewicht);
    virtual ~Triebwerke();
    void print();
    double getGewicht() const;
    double getSchub() const;
    double getVerbrauch() const;
    string getName() const;


private:
    string name;
    double schub;
    double verbrauch;
    double gewicht;
};

#endif	/* TRIEBWERKE_H */


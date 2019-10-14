#include "header.h"
#include <math.h>
#include <iostream>

using namespace std;



double Umfang (Kreis& k) {
    double u=2*M_PI*k.radius;
    return u;
}

double Umfang(Dreieck& d) {
    double laenge1 = d.E2.x - d.E1.x;
    double laenge2 = d.E1.y - d.E3.y;
    double laenge3 = sqrt(pow(laenge1, 2) + pow(laenge2, 2));
    double u = laenge1+laenge2+laenge3;
    
    return u;
    
}

double Umfang(Rechteck& r) {
    double laenge1 = r.R2.x - r.R1.x;
    double laenge2 = r.R1.y - r.R3.y;
    double laenge3 = r.R4.x - r.R3.x;
    double laenge4 = r.R2.y - r.R4.y;
    
    double u= laenge1+laenge2+laenge3+laenge4;
    
    return u;
    
    
}

double Flaeche(Kreis& k){
    double flaeche = M_PI*(pow(k.radius, 2));
    
    return flaeche;
    
}

double Flaeche(Dreieck& d) {
    double laenge1 = d.E2.x - d.E1.x;
    double laenge2 = d.E1.y - d.E3.y;
    double flaeche = ((laenge1*laenge2)/2);
    
    return flaeche;
}

double Flaeche(Rechteck& r) {
    double laenge1 = r.R4.x - r.R3.x;
    double laenge2 = r.R2.y - r.R4.y;
    double flaeche = laenge1*laenge2;
    
    return flaeche;
}

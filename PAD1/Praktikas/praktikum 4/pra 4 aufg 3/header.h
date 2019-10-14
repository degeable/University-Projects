/* 
 * File:   header.h
 * Author: fs
 *
 * Created on 20. November 2016, 16:04
 */

#ifndef HEADER_H
#define	HEADER_H

//struct Punkt2D;
//struct Kreis;
//struct Dreieck;
//struct Rechteck;

struct Punkt2D {
    int x;
    int y;
};

struct Kreis{
    Punkt2D mittelpunkt;
    double radius;
};

struct Dreieck {

    Punkt2D E1;
    Punkt2D E2;
    Punkt2D E3;

    
};

struct Rechteck {
    Punkt2D R1;
    Punkt2D R2;
    Punkt2D R3;
    Punkt2D R4;
    
};

double Umfang(Kreis& k); 
double Umfang(Dreieck& d); 
double Umfang(Rechteck& r); 

double Flaeche(Kreis& k);
double Flaeche(Dreieck& d);
double Flaeche(Rechteck& r);

#endif	/* HEADER_H */


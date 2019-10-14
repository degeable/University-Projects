/* 
 * File:   PR4_Teil2.cpp
 * Author: fs
 *
 * Created on 15. November 2016, 14:57
 */

#include <cstdlib>
#include </home/fs/Schreibtisch/Praktika/PAD/Praktkum 4/Praktikum_4_Teil_2/PR4_Teil2.h>
#include <iostream>
#include <math.h>

using std::cout;
using std::cin;
using std::endl;
   

// -----------------------------------------------------------------------------
// 2D Punkt
// -----------------------------------------------------------------------------
void Dot_2D ::create(const float& a,const float& b)
{
    x = a;
    y = b;
}

float Dot_2D ::getX()
{
    return x;
}

float Dot_2D ::getY()
{
    return y;
}



// -----------------------------------------------------------------------------
// Kreis
// -----------------------------------------------------------------------------
void Kreis ::create(const Dot_2D& point, float& r)
{
    mid = point;
    ratio = r;
}

Dot_2D Kreis ::getMid()
{
    return mid;
}

float Kreis ::getRatio(){
    return ratio;
}


// -----------------------------------------------------------------------------
// Dreieck
// -----------------------------------------------------------------------------
void Dreieck ::create(const Dot_2D& point1, const Dot_2D& point2, const Dot_2D& point3)
{
    tri_1 = point1;
    tri_2 = point2;
    tri_3 = point3;
}

float Dreieck ::getEdge_1to2()
{
    float edge_1to2;
    edge_1to2 = sqrt( pow(abs(tri_2.getX() - tri_1.getX()), 2) + pow(abs(tri_2.getY() - tri_1.getY()), 2) );
    
    return edge_1to2;
}

float Dreieck ::getEdge_1to3()
{
    float edge_1to3;
    edge_1to3 = sqrt( pow(abs(tri_3.getX() - tri_1.getX()), 2) + pow(abs(tri_3.getY() - tri_1.getY()), 2) );
    
    return edge_1to3;
}

float Dreieck ::getEdge_2to3()
{
    float edge_2to3;
    edge_2to3 = sqrt( pow(abs(tri_3.getX() - tri_2.getX()), 2) + pow(abs(tri_3.getY() - tri_2.getY()), 2) );
    
    return edge_2to3;
}


// -----------------------------------------------------------------------------
// Rechteck
// -----------------------------------------------------------------------------
void Rechteck ::create(const Dot_2D& dot, const float& len, const float& wid)
{
    point = dot;
    length = len;
    width = wid;
}

Dot_2D Rechteck ::getPoint()
{
    return point;
}

float Rechteck ::getLength()
{
    return length;
}

float Rechteck ::getWidth()
{
    return width;
}




// -----------------------------------------------------------------------------
// Umfang-Funktionen
// -----------------------------------------------------------------------------
float umfang(Dreieck& triangle)
{
    float umfang;
    umfang = triangle.getEdge_1to2() + triangle.getEdge_1to3() + triangle.getEdge_2to3();
    
    return umfang;
}

float umfang(Kreis& circle)
{
    const float pi = 3.14;
    float umfang;
    
    umfang = 2 * pi * circle.getRatio();
}

float umfang(Rechteck& rectangle)
{
    float umfang;
    
    umfang = 2 * (rectangle.getLength() + rectangle.getWidth());
    
    return umfang;
}


// -----------------------------------------------------------------------------
// Flaeche-Funktionen
// -----------------------------------------------------------------------------
float flaeche(Dreieck& triangle)
{
    float flaeche;
    float s, a, b, c;
    
    // wende Satz des Heron an
    s = umfang(triangle) / 2;
    a = triangle.getEdge_1to2();
    b = triangle.getEdge_1to3();
    c = triangle.getEdge_2to3();
    
    flaeche = s * (s - a) * (s - b) * (s - c);
    return flaeche;
}

float flaeche(Kreis& circle)
{
    const float pi = 3.14;
    float flaeche;
    
    flaeche = pi * pow( circle.getRatio(), 2 );
    
    return flaeche;
}

float flaeche(Rechteck& rectangle)
{
    float flaeche;
    
    flaeche = rectangle.getLength() * rectangle.getWidth();
    
    return flaeche;
}
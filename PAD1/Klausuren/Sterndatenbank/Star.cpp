/* 
 * File:   Star.cpp
 * Author: fs
 * 
 * Created on 5. Februar 2017, 17:12
 */


#include "Vec3D.h"
#include <vector>
#include <string>
#include "Star.h"
using namespace std;
Star::Star() {
        m_name="Unbekannt";
        m_postition.setX(0);
        m_postition.setY(0);
        m_postition.setZ(0);
        m_klasse='X';
}

Star::Star(string name,Vec3D v,char klasse) {
    m_name=name;
    m_postition=v;
    m_klasse=klasse;
}

Star::~Star() {
}

string Star::GetName() {
    return m_name;
}

Vec3D Star::GetPostition()  {
    return m_postition;
}

void Star::print() {
    cout<<"Name: "<<m_name<<"Position: ";
    m_postition.print();
            cout<<"Klasse: "<<m_klasse;
}

char Star::GetKlasse() const {
    return m_klasse;
}

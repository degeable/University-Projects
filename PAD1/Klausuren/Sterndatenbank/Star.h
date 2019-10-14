/* 
 * File:   Star.h
 * Author: fs
 *
 * Created on 5. Februar 2017, 17:12
 */

#ifndef STAR_H
#define	STAR_H
#include <string>
#include "Vec3D.h"
using namespace std;

class Star {
public:
    Star();  
    Star(string name,Vec3D v,char klasse);
    virtual ~Star();
    string GetName() ;
    Vec3D GetPostition() ;
    void print();
    char GetKlasse() const;
private:
    string m_name;
    Vec3D m_postition;
    char m_klasse;
};

#endif	/* STAR_H */


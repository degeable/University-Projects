/* 
 * File:   Vec3D.h
 * Author: fs
 *
 * Created on 5. Februar 2017, 16:54
 */

#ifndef VEC3D_H
#define	VEC3D_H
#include <iostream>



using namespace std;

class Vec3D {
public:
    Vec3D();
    Vec3D(double pos);
    Vec3D(double posx,double posy,double posz);
    virtual ~Vec3D();

    double length();
    Vec3D add(Vec3D vec1, Vec3D vec2);
    Vec3D sub(Vec3D vec1, Vec3D vec2);
    void print();
    void setZ(double z);
    void setY(double y);
    void setX(double x);
private:
    double x;
    double y;
    double z;
};


#endif	/* VEC3D_H */


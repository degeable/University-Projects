/* 
 * File:   Vec3D.cpp
 * Author: fs
 * 
 * Created on 5. Februar 2017, 16:54
 */

#include "Vec3D.h"
#include <cmath>
#include "Universe.h"
#include <iostream>
using namespace std;

Vec3D::Vec3D() {
    x=0;
    y=0;
    z=0;
    
}

Vec3D::Vec3D(double pos) {
    x=pos;
    y=pos;
    z=pos;
}

Vec3D::Vec3D(double posx, double posy, double posz) {
    x=posx;
    y=posy;
    z=posz;
}


Vec3D::~Vec3D() {
}

void Vec3D::print() {
    cout<<"("<<x<<", "<<y<<", "<<z<<")"<<endl;
}

void Vec3D::setZ(double z) {
    this->z = z;
}

void Vec3D::setY(double y) {
    this->y = y;
}

void Vec3D::setX(double x) {
    this->x = x;
}

Vec3D Vec3D::add(Vec3D vec1, Vec3D vec2) {
    Vec3D addVec;
    addVec.x=vec1.x+vec2.x;
     addVec.y=vec1.y+vec2.y;
      addVec.z=vec1.z+vec2.z;
      return addVec;
}

Vec3D Vec3D::sub(Vec3D vec1, Vec3D vec2) {
    Vec3D subVec;
        subVec.x=vec1.x-vec2.x;
     subVec.y=vec1.y-vec2.y;
      subVec.z=vec1.z-vec2.z;
      return subVec;
      
}

double Vec3D::length() {

    return sqrt((x*x)+(y*y)+(z*z));
    
}



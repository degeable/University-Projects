/* 
 * File:   Universe.h
 * Author: fs
 *
 * Created on 5. Februar 2017, 17:19
 */

#ifndef UNIVERSE_H
#define	UNIVERSE_H
#include <vector>
#include "Star.h"
#include "Vec3D.h"
#include <iostream>

using namespace std;
class Universe {
public:
    Universe();
    Universe(const Universe& orig);
    virtual ~Universe();
    void addStar(const Star& star);
    Star getStar(const string& name);
    void  removeStar(const string& name);
    double getDistance(string s1, string s2);
    double getDistance(Vec3D pos1,Vec3D pos2);
    Star findNearestStar(Vec3D star, char klasse);
        Star findNearestStar(Vec3D star);
private:
    vector<Star>stars;

};

#endif	/* UNIVERSE_H */


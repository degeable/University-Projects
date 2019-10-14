/* 
 * File:   Universe.cpp
 * Author: fs
 * 
 * Created on 5. Februar 2017, 17:19
 */

#include "Universe.h"
#include "Star.h"
#include "Vec3D.h"
#include <vector>
#include <iostream>
#include <limits>
using namespace std;

Universe::Universe() {
}

Universe::Universe(const Universe& orig) {
}

Universe::~Universe() {
}

void Universe::addStar(const Star& star) {
    stars.push_back(star);
    
}

Star Universe::getStar(const string& name) {
    for(auto i=0;i<stars.size();i++){
        if(stars.at(i).GetName()==name)
            return stars.at(i);
    } Star stern;
    return stern;
}

void Universe::removeStar(const string& name) {
    for(auto i=0;i<stars.size();i++){
        if(stars.at(i).GetName()==name)
            cout<<"hier sollte gelöscht werden";
//            stars.erase(i);
    }
    
}


double Universe::getDistance(string s1, string s2) {
  Star stern1= getStar(s1);
  Star stern2= getStar(s2);
  Vec3D tmp; 
  tmp=tmp.sub(stern1.GetPostition(),stern2.GetPostition());
  
  return tmp.length();
}

double Universe::getDistance(Vec3D pos1, Vec3D pos2){
     Vec3D tmp; 
  tmp=tmp.sub(pos1,pos2);
  
  return tmp.length();
}

Star Universe::findNearestStar(Vec3D star) {
    int iterator;

    double dst=getDistance(star,stars.at(0).GetPostition());
    iterator=0;
    for(auto i=0;i<stars.size();i++){
       if(getDistance(star,stars.at(i).GetPostition())<dst){
           iterator=i;
       }
        
    }
    return stars.at(iterator);
}

Star Universe::findNearestStar(Vec3D star, char klasse) {
  int iterator;

    double dst=numeric_limits<double>::max();
    iterator=0;
    for(auto i=0;i<stars.size();i++){
       if(getDistance(star,stars.at(i).GetPostition())<dst&&klasse==stars.at(i).GetKlasse()){
           iterator=i;
       }
        
    }
    return stars.at(iterator);
}

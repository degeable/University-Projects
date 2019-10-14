/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Galaxis.h
 * Author: stud
 *
 * Created on 9. Juli 2017, 17:10
 */

#ifndef GALAXIS_H
#define GALAXIS_H
#include <fstream>
#include <list>
#include "Stern.h"
#include <cmath>
#include  <iostream>
#include <sstream>
#include <vector>
class Galaxis
{
public:
    Galaxis(const std::string& datei);
    Galaxis(const Galaxis& orig);
    virtual ~Galaxis();
    Stern& find(int ID);
    Stern& find(const std::string& name);
    void Entfernung();
    
    void trinity();
    struct SternEntfernung{
        Stern s;
        float s_dist;
                
        friend std::ostream& operator<<(std::ostream& os, const SternEntfernung& obj)
        {
            os << obj.s.GetName() << ": " << obj.s_dist << " pc" << std::endl;
    return os;
 
        }

      
    };
        struct sorter{
            bool operator()(const SternEntfernung& lhs,const SternEntfernung& rhs);
        


    };
    
private:
     std::vector<Stern>sterneID;
    std::list<Stern>sterneName;
        std::list<SternEntfernung>sternDist;
};

#endif /* GALAXIS_H */


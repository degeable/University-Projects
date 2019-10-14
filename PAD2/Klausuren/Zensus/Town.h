/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Town.h
 * Author: stud
 *
 * Created on 8. Juli 2017, 15:15
 */

#ifndef TOWN_H
#define TOWN_H
#include <string>
#include <list>
#include <string.h>

#include "Data.h"



class Town
{
public:
    Town();
   
    virtual ~Town();

     struct sortbyName{
        bool operator()(const Town& lhs, const Town& rhs);

    };
    
    struct sortbyLand{
        bool operator()(const Town& lhs,const Town& rhs);
    };
    
    friend std::ostream& operator<<(std::ostream& os, const Town& obj);

    friend std::istream& operator>>(std::istream& is, Town& obj);

    bool operator==(const Town& right) const;

    bool sameState(const Town& right) const;
    
    int getPop(bool b) const;
    std::string getStadt() const;
    std::string getBundesland() const;

private:
    std::string m_bundesland;
    std::string m_stadt;
    std::list<Data>zaehlung;
};

    
#endif /* TOWN_H */


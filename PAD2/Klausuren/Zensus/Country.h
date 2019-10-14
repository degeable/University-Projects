/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Country.h
 * Author: stud
 *
 * Created on 8. Juli 2017, 15:54
 */

#ifndef COUNTRY_H
#define COUNTRY_H
#include <string>
#include <fstream>
#include <list>
#include "Town.h"
#include <iostream>
class Country
{
public:
    Country(const std::string& datei );

    virtual ~Country();
    void printTown()const;
    void printLand()const ;
    void doppelte()const;
    void sucheStadt(std::string& stadt)const;
    void gesamt()const;
    void letzte();
    
private:
    std::list<Town>stadtname;
    std::list<Town>bundesland;
    struct Growth
	{
		Town t;
		double growth;
		Growth(Town p_t, double p_growth):
		t(p_t), growth(p_growth)
		{}
		bool operator<(const Growth& rhs) const
		{
			return growth > rhs.growth;
		}
	};
};

#endif /* COUNTRY_H */


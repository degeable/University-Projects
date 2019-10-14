/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Town.cpp
 * Author: stud
 * 
 * Created on 8. Juli 2017, 15:15
 */

#include <vector>

#include "Town.h"
#include "Data.h"

Town::Town()
{
}



Town::~Town()
{
}

std::ostream& operator<<(std::ostream& os, const Town& obj)
{
    os << "Stadt: " << obj.m_stadt << " Bundesland: " << obj.m_bundesland << " Einwohner: "<<obj.getPop(true)<<std::endl;
    return os;
}


int Town::getPop(bool b) const
{
    if (b)
    {
        return zaehlung.front().getBevoelkerungszahl();
    }
    else
        return zaehlung.back().getBevoelkerungszahl();
}

std::string Town::getStadt() const
{
    return m_stadt;
}

std::string Town::getBundesland() const
{
    return m_bundesland;
}


bool Town::sameState(const Town& right) const
{
    if (right.m_bundesland == this->m_bundesland)
    {
        return true;
    }
    else
    {
        return false;
    }
}


std::istream& operator>>(std::istream& is, Town& obj)
{
    Data d1, d2;
    getline(is,obj.m_bundesland,'\n');
      getline(is,obj.m_stadt,'\n');
    is>>d1;
    is>>d2;
    d1.setJahr(2011);
    d2.setJahr(1987);
    is.ignore(100,'\n');
    
    obj.zaehlung.push_back(d1);
    obj.zaehlung.push_back(d2);
    obj.zaehlung.sort();
    return is;
}


bool Town::operator==(const Town& right) const
{
    if (right.m_bundesland == this->m_bundesland && right.m_stadt == this->m_stadt)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Town::sortbyLand::operator()(const Town& lhs, const Town& rhs)
{
            return lhs.m_stadt < rhs.m_stadt;
        
}

bool Town::sortbyName::operator()(const Town& lhs, const Town& rhs)
{
    if(lhs.m_bundesland!=rhs.m_bundesland)
        return lhs.m_bundesland<rhs.m_bundesland;
            return lhs.m_stadt < rhs.m_stadt;
        
}

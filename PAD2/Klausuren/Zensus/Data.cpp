/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Data.cpp
 * Author: stud
 * 
 * Created on 8. Juli 2017, 14:59
 */

#include "Data.h"

Data::Data(int jahr, int total, int men, int woman) : m_jahr(jahr), m_bevoelkerungszahl(total), m_maennlich(men), m_weiblich(woman)
{

}


Data::Data()
{
}

Data::~Data()
{
}

void Data::setJahr(int jahr)
{
    m_jahr = jahr;
}

int Data::getBevoelkerungszahl() const
{
    return m_bevoelkerungszahl;
}

bool Data::operator<(const Data& right) const
{
    return m_jahr> right.m_jahr;
}

std::istream& operator>>(std::istream& is, Data& obj)
{

    is >> obj.m_bevoelkerungszahl >> obj.m_maennlich >> obj.m_weiblich;
    return is;
}


//bool Data::operator>(const Data& right) const
//{
//    if (m_jahr > right.m_jahr)
//    {
//        return true;
//    }
//    else
//        return false;
//}


std::ostream& operator<<(std::ostream& os, const Data& obj)
{
    os << "Jahr: " << obj.m_jahr << " Einwohner: " << obj.m_bevoelkerungszahl;
    return os;
}

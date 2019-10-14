/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Zeitpunkt.cpp
 * Author: stud
 * 
 * Created on 10. Juli 2017, 11:22
 */

#include "Zeitpunkt.h"

Zeitpunkt::Zeitpunkt(const std::string& datetime)
{
  std::stringstream jahr(datetime.substr(0,4));
  std::stringstream monat(datetime.substr(4,2));
  std::stringstream tag(datetime.substr(6,2));
  std::stringstream stunde(datetime.substr(8,2));
  jahr>>m_jahr;
  monat>>m_monat;
  tag>>m_tag;
  stunde>>m_Stunde;
    
//    m_jahr=std::stoi(datetime.substr(0,4));
// m_monat= std::stoi(datetime.substr(4,2));
// m_tag= std::stoi(datetime.substr(6,2));
// m_Stunde= std::stoi(datetime.substr(8,2));
  
}

Zeitpunkt::Zeitpunkt()
{

}




Zeitpunkt::~Zeitpunkt()
{
}

void Zeitpunkt::setStunde(int Stunde)
{
    m_Stunde = Stunde;
}

int Zeitpunkt::getStunde() const
{
    return m_Stunde;
}

int Zeitpunkt::getMonat() const
{
    return m_monat;
}

int Zeitpunkt::getJahr() const
{
    return m_jahr;
}

bool Zeitpunkt::operator<(const Zeitpunkt& right) const
{
    return right > * this; // Reuse greater than operator
}

std::ostream& operator<<(std::ostream& os, const Zeitpunkt& obj)
{
    os << obj.m_tag << "." << obj.m_monat << "." << obj.m_jahr << ", " << obj.m_Stunde << " Uhr: ";
    return os;
}

bool Zeitpunkt::operator>(const Zeitpunkt& right) const
{
    if (this->m_jahr > right.m_jahr && this->m_monat > right.m_monat && this->m_tag > right.m_tag && this->m_Stunde > right.m_Stunde)
    {
        return true;
    }
    else
        return false;

}

std::istream& operator>>(std::istream& is, Zeitpunkt& obj)
{
    std::string datetime;

    is>>datetime;
        if(datetime.size()==0)
        return is;
    Zeitpunkt z(datetime);

    obj = z;

    return is;
}

void Zeitpunkt::getTag()
{
    std::cout<<m_tag<<"."<<m_monat<<"."<<m_jahr<<" ";
    
    
            
}

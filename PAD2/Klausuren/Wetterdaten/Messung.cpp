/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Messung.cpp
 * Author: stud
 * 
 * Created on 10. Juli 2017, 11:48
 */

#include "Messung.h"

Messung::Messung(Zeitpunkt& zeit, double& temp, double& feucht, std::string& ort) : m_feucht(feucht), m_ort(ort), m_temp(temp), m_zeitpunkt(zeit)
{

}

Messung::Messung()
{

}

Messung::~Messung()
{
}

void Messung::SetOrt(std::string ort)
{
    m_ort = ort;
}

Zeitpunkt Messung::GetZeitpunkt() const
{
    return m_zeitpunkt;
}

double Messung::GetTemp() const
{
    return m_temp;
}

std::istream& operator>>(std::istream& is, Messung& obj)
{
    is >> obj.m_zeitpunkt >> obj.m_temp >> obj.m_feucht;
    return is;
}


std::ostream& operator<<(std::ostream& os, const Messung& obj)
{
    os << obj.m_zeitpunkt << obj.m_temp << "°C bei " << obj.m_feucht << "% Luftfeuchtigkeit in " << obj.m_ort;
    return os;
}


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Messung.h
 * Author: stud
 *
 * Created on 10. Juli 2017, 11:48
 */

#ifndef MESSUNG_H
#define MESSUNG_H
#include <string>
#include "Zeitpunkt.h"


class Messung
{
public:
    Messung(Zeitpunkt& zeit,double& temp,double& feucht,std::string& ort);
    Messung();
    virtual ~Messung();
    void SetOrt(std::string ort);
    Zeitpunkt GetZeitpunkt() const;
    double GetTemp() const;
    friend std::ostream& operator<<(std::ostream& os, const Messung& obj);

    friend std::istream& operator>>(std::istream& is, Messung& obj);
    friend class Wetterdienst;
private:
    Zeitpunkt m_zeitpunkt;
    double m_temp;
    double m_feucht;
    std::string m_ort;
};

#endif /* MESSUNG_H */


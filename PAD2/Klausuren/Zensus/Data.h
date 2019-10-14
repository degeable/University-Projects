/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Data.h
 * Author: stud
 *
 * Created on 8. Juli 2017, 14:59
 */

#ifndef DATA_H
#define DATA_H
#include <ostream>
#include <iostream>

class Data
{
public:
    Data(int jahr, int total, int men,int woman);
    Data();
    virtual ~Data();
    friend std::ostream& operator<<(std::ostream& os, const Data& obj);
//    bool operator>(const Data& right) const;
    bool operator<(const Data& right) const;
    void setJahr(int jahr);
    int getBevoelkerungszahl() const;
    friend std::istream& operator>>(std::istream& is, Data& obj);

private:
    int m_bevoelkerungszahl;
    int m_maennlich;
    int m_weiblich;
    int m_jahr;


};

#endif /* DATA_H */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Stern.h
 * Author: stud
 *
 * Created on 9. Juli 2017, 17:02
 */

#ifndef STERN_H
#define STERN_H
#include <string>
#include <fstream>
#include <cmath>
#include <iostream>
#include <sstream>
class Stern
{
public:
    Stern();
    Stern(const Stern& orig);
    virtual ~Stern();
    int GetID() const;
    std::string GetName() const;
    double GetZ() const;
    double GetY() const;
    double GetX() const;
    void SetPrim_ID(int prim_ID);
    void SetSternbild(std::string sternbild);
    void SetIndex(int Index);
    void SetZ(double z);
    void SetY(double y);
    void SetX(double x);
    void SetName(std::string name);
    void SetID(int ID);
    
    struct sortbyID {
        bool operator()(const Stern& lhs,const Stern& rhs)const 
        {
           return lhs.m_ID< rhs.m_ID;
        }
    };
    
    struct sortbyName{
        bool operator()(const Stern& lhs,const Stern& rhs)const
        {
            return lhs.m_name< rhs.m_name;
        }
    };
//    bool operator>(const Stern& right) const
//    {
//        return *this->m_ID > right.m_ID
//    }
//    bool operator<(const Stern& right) const
//    {
//        return right > * this; // Reuse greater than operator
//    }

    
    friend std::ostream& operator<<(std::ostream& os, const Stern& obj);

    friend std::istream& operator>>(std::istream& is,  Stern& obj);

private:
    int m_ID;
   std::string m_name;
    double x;
    double y;
    double z;
    int m_Index;
    std::string m_sternbild;
    int prim_ID;
};

#endif /* STERN_H */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Stern.cpp
 * Author: stud
 * 
 * Created on 9. Juli 2017, 17:02
 */

#include "Stern.h"

Stern::Stern()
{
}

Stern::Stern(const Stern& orig)
{
}

Stern::~Stern()
{
}

int Stern::GetID() const
{
    return m_ID;
}

std::string Stern::GetName() const
{
    return m_name;
}

double Stern::GetZ() const
{
    return z;
}

double Stern::GetY() const
{
    return y;
}

double Stern::GetX() const
{
    return x;
}

void Stern::SetPrim_ID(int prim_ID)
{
    this->prim_ID = prim_ID;
}

void Stern::SetSternbild(std::string sternbild)
{
    m_sternbild = sternbild;
}

void Stern::SetIndex(int Index)
{
    m_Index = Index;
}

void Stern::SetZ(double z)
{
    this->z = z;
}

void Stern::SetY(double y)
{
    this->y = y;
}

void Stern::SetX(double x)
{
    this->x = x;
}

void Stern::SetName(std::string name)
{
    m_name = name;
}

void Stern::SetID(int ID)
{
    m_ID = ID;
}

std::ostream& operator<<(std::ostream& os, const Stern& obj)
{
    os << "ID: " << obj.m_ID << "\n" << "Name: " << obj.m_name << "\n" << "Koordinaten: " << obj.x << ", " << obj.y << ", " << obj.z << "\n";
    return os;
}

std::istream& operator>>(std::istream& is, Stern& obj)
{

    std::string tmp;
    getline(is, tmp);
    std::stringstream ss(tmp);
    ss>>obj.m_ID;

    getline(is, tmp);
    std::stringstream ss1(tmp);
   ss1>>obj.m_name;

    getline(is, tmp);
    std::stringstream ss2(tmp);
  ss2>>obj.x;

    getline(is, tmp);
    std::stringstream ss3(tmp);
  ss3>>obj.y;

    getline(is, tmp);
    std::stringstream ss4(tmp);
    ss4>>obj.z;

    getline(is, tmp);
    std::stringstream ss5(tmp);
    ss5>>obj.m_sternbild;

    getline(is, tmp);
    std::stringstream ss6(tmp);
   ss6>>obj.m_Index;

    getline(is, tmp);
    std::stringstream ss7(tmp);
    ss7>>obj.prim_ID;

//    //	getline(is, tmp);


    return is;


}

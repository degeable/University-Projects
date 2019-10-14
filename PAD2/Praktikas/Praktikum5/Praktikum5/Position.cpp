/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Position.cpp
 * Author: stud
 * 
 * Created on 17. Juni 2017, 15:13
 */
#include "Position.h"

Position::Position() {
    Reihe = 0;
    Spalte = 0;
}

Position::Position(int reihe, int spalte) {
    Reihe = reihe;
    Spalte = spalte;
}

//Position::Position(const Position& orig) {
//}

Position::~Position() {
}

istream& operator>>(istream& inputstream, Position& pos) {
    
    inputstream >> pos.Reihe >> pos.Spalte;
    return inputstream;
}

ostream& operator<<(ostream& outputstream, const Position& pos) {
    outputstream <<"["<< pos.Reihe << "][" << pos.Spalte<<"]";
    return outputstream;
}

bool Position::operator<(const Position& rechts) const{
    if (this->Reihe < rechts.Reihe)
        return true;
    if (this->Spalte < rechts.Spalte && this->Reihe == rechts.Reihe)
        return true;
    else
        return false;
}

bool Position::operator>(const Position& rechts) const{
    return (*this < rechts);
}

Position Position::operator-(const Position& rechts){
    return Position((this->Reihe-rechts.Reihe), (this->Spalte-rechts.Spalte));
}

Position Position::operator+(const Position& rechts){
    return Position((this->Reihe+rechts.Reihe), (this->Spalte+rechts.Spalte));
}

Kante::Kante(Position pos1, Position pos2) {
    if (pos1 > pos2) {
        m_pos1 = pos2;
        m_pos2 = pos1;
    } else {
        m_pos1 = pos1;
        m_pos2 = pos2;
    }
    m_dist = 2147483647; //int max
    m_visited = false;

}

bool Kante::operator<(const Kante& rechts) const {
    if(this->m_pos1.Reihe < rechts.m_pos1.Reihe)
        return true;
    if(this->m_pos1.Reihe == rechts.m_pos1.Reihe && this->m_pos2.Spalte < rechts.m_pos2.Spalte)
        return true;
    else
        return false;

}
 bool Kante::operator>(const Kante& rechts) const {
return (*this < rechts);
}
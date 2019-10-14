/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Position.h
 * Author: stud
 *
 * Created on 17. Juni 2017, 15:13
 */
#ifndef POSITION_H
#define POSITION_H

#include <iostream>
using namespace std;

struct Position {    
    Position();
    Position(int reihe, int spalte);
    //Position(const Position& orig);
    virtual ~Position();
    
    int Reihe;
    int Spalte;

    friend bool operator==(const Position& lhs,const Position& rhs) {return (lhs.Reihe == rhs.Reihe && lhs.Spalte == rhs.Spalte);}; //funktioniert nicht ohne friend????
    bool operator!=(const Position& rhs) {return !((*this) == rhs);}; //hier schon?? warum?
    friend istream& operator>>(istream& inputstream, Position& pos);
    friend ostream& operator<<(ostream& outputstream, const Position& pos);
    bool operator<(const Position& rechts)const ;
    bool operator>(const Position& rechts) const;
    Position operator-(const Position& rechts);
    Position operator+(const Position& rechts);
};



struct Kante{
    
    Position m_pos1, m_pos2;
    int m_dist;
    bool m_visited;
    Kante(Position pos1, Position pos2);
    

    bool operator<( const Kante& rechts) const;
    bool operator>(const Kante& rechts) const ;
    
    
};
#endif /* POSITION_H */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mastermind.h
 * Author: stud
 *
 * Created on 28. November 2017, 15:08
 */

#ifndef MASTERMIND_H
#define MASTERMIND_H
#include "functions 2.hpp"

class Mastermind
{
public:
    int start();
    int guess();
    Mastermind();
    Mastermind(const Mastermind& orig);
    virtual ~Mastermind();
private:

};

#endif /* MASTERMIND_H */


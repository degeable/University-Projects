/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   functions 2.hpp
 * Author: stud
 *
 * Created on 28. November 2017, 11:13
 */

#ifndef FUNCTIONS_2_HPP
#define FUNCTIONS_2_HPP
#include <vector>

using namespace std;


template <typename T>
bool isValidInput(const vector<T>& guess, int length, T min, T max)
{
    
    if(guess.size() != length)
        return false;
    
    for(int i=0;i<length;i++)
    {
        if(guess[i] < min || guess[i] > max)
            return false;
    }
     return true; //return true hinzugefügt
}

template <typename T>
int white(const vector<T>& solution, const vector<T>& guess)
{


  	if (solution.size() != guess.size())
		return -1;
        
    int countw=0;
    for(int i=0;i<guess.size();i++)
    {
        for(int n=0;n<solution.size();n++) //anstatt solution hattest du nochmal quess.size()
        {
            if(i==n)
                continue;
            if(guess[i]==solution[n])
                countw++;
        }
    }
   return countw;
}


template <typename T>
int black(const vector<T>& solution, const vector<T>& guess)
{
   
    int countb=0; //du hattest manchmal nicht mit null initialisiert
    for(int s=0;s<solution.size();s++)
    {
        if(guess[s] == solution[s])
            countb++;
    }
    return countb; //return weerte hinzugefügt
}


#endif 


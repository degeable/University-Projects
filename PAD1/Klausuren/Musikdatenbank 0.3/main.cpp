/* 
 * File:   main.cpp
 * Author: fs
 *
 * Created on 24. November 2016, 17:19
 */

#include <cstdlib>
#include <vector>
#include "lied.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
void Neu(vector<lied>&song);
int menue(vector<lied>&song);
void Alle(vector<lied>&song);
void Anzeigen(vector<lied>&song);
void loeschen(vector<lied>&song);
void bearbeiten(vector<lied>&song);

     vector<lied>song;

   menue(song);
}


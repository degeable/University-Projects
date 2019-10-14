/* 
 * File:   Spielfeld.cpp
 * Author: fs
 * 
 * Created on 4. Februar 2017, 10:59
 */

#include "Spielfeld.h"
#include "Schiff.h"
#include <iostream>
#include <vector>
#include <iostream>

using namespace std;

Spielfeld::Spielfeld() {
    for (int r=0;r<11;r++){
        for (int c=0;c<11;c++){
           Leinwand[r][c]='.';
        }
       
    }
    
    for (int i=0;i<10;i++){
        Leinwand[i][0]=i+'0';
        Leinwand[0][i]=i+'0';
    }
    Leinwand[10][0]='A';
    Leinwand[0][10]='A';
    
    Schiff s1(1,2,3,OST);
    Schiff s2(3,4,5,OST);
    Schiff s3(5,1,1,SUED);
    Schiff s4(2,7,4,SUED);
    Schiff s5(4,6,9,WEST);
    m_schiffe.push_back(s1);
   m_schiffe.push_back(s2);
    m_schiffe.push_back(s3);
    m_schiffe.push_back(s4);
    m_schiffe.push_back(s5);
 
    s1.Zeichne(Leinwand);
    s2.Zeichne(Leinwand);
    s3.Zeichne(Leinwand);
    s4.Zeichne(Leinwand);   
    s5.Zeichne(Leinwand);
     
}

Spielfeld::Spielfeld(const Spielfeld& orig) {
}

Spielfeld::~Spielfeld() {
}

void Spielfeld::Ausgeben() {
    for (int r=0;r<11;r++){
        for (int c=0;c<11;c++){
          cout<< Leinwand[r][c]<<" ";
        }
        cout<<endl;
    }
}

void Spielfeld::Spielen() {
    int reihe,spalte;
    bool getroffen;
    while (fertig(reihe,spalte)!=true){
    Ausgeben();
    getroffen=false;
    cout<<"Welches Feld soll beschossen werden?"<<endl<<"Reihe: ";
    cin>>reihe;
 
    cout<<"\nSpalte: ";
    cin>>spalte;

    cout<<endl;
    for(auto i=0;i<m_schiffe.size();i++){
    if (m_schiffe.at(i).belegt(reihe,spalte)==true){
        cout<<"Getroffen!"<<endl; 
        Leinwand[reihe][spalte]='%';
        getroffen=true;
        
       if( m_schiffe.at(i).beschuss(reihe,spalte)){
           cout<<"Versenkt!"<<endl;
       }
     
    }
    if(getroffen!=true)
            Leinwand[reihe][spalte]='X';
        
    }
    }
    cout<<"Alle Schiffe versenkt!";
    }

bool Spielfeld::fertig(int reihe,int spalte) {
    int ctr=0;
    for(auto i=0;i<m_schiffe.size();i++){
        if(m_schiffe.at(i).beschuss(reihe,spalte)==true){
            ctr++;
        }
    }
    if(ctr==m_schiffe.size()){
        return true;
    }else return false;
}

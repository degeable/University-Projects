/* 
 * File:   Schiff.cpp
 * Author: fs
 * 
 * Created on 4. Februar 2017, 09:58
 */

#include "Schiff.h"
#include <vector>

Schiffsteil::Schiffsteil(int reihe, int spalte, Status status) {
    m_reihe=reihe;
    m_spalte=spalte;
    m_status=status;
}


Schiff::Schiff(int laenge, int reihe, int spalte, Ausrichtung ausrichtung) {
    m_laenge=laenge;
    if(ausrichtung==NORD){
        for(auto i=0;i<laenge;i++){
    Schiffsteil teil(reihe, spalte, UNBESCHAEDIGT);
    m_teile.push_back(teil);
    reihe --;
    }
    }
        if(ausrichtung==SUED){
        for(auto i=0;i<laenge;i++){
    Schiffsteil teil(reihe, spalte, UNBESCHAEDIGT);
    m_teile.push_back(teil);
    reihe ++;
    }
    }
        if(ausrichtung==OST){
        for(auto i=0;i<laenge;i++){
    Schiffsteil teil(reihe, spalte, UNBESCHAEDIGT);
    m_teile.push_back(teil);
    spalte ++;
    }
    }
        if(ausrichtung==WEST){
        for(auto i=0;i<laenge;i++){
    Schiffsteil teil(reihe, spalte, UNBESCHAEDIGT);
    m_teile.push_back(teil);
    spalte --;
    }
    }
   
}



Schiff::~Schiff() {
}

bool Schiff::belegt(int reihe, int spalte) {
    for(auto i=0;i<m_teile.size();i++){
        if(m_teile[i].GetReihe()==reihe && m_teile[i].GetSpalte()==spalte)
            return true;

    }
    
    return false;
}

bool Schiff::beschuss(int reihe, int spalte) {
    int pos=0;
 for(auto i=0;i<m_teile.size();i++){
        if(m_teile[i].GetReihe()==reihe && m_teile[i].GetSpalte()==spalte){            
                m_teile[i].SetStatus(GETROFFEN);            
            }
        }

    for(auto i=0;i<m_laenge;i++){
       if(m_teile[i].GetStatus()==GETROFFEN){       
           pos++;
       }
    }
    if (pos==m_laenge){    
    return true;
    }else return false;
}

void Schiff::Zeichne(char leinwand[11][11]) {
  
for (auto i=0;i<m_teile.size();i++){  
 leinwand[m_teile[i].GetReihe()][m_teile[i].GetSpalte()]='#';     
}
}

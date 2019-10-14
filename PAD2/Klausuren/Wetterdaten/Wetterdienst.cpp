/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Wetterdienst.cpp
 * Author: stud
 * 
 * Created on 10. Juli 2017, 12:20
 */

#include <vector>
#include <set>
#include <algorithm>

#include "Wetterdienst.h"
#include "Messung.h"

Wetterdienst::Wetterdienst(const std::string& datei1, const std::string& datei2)
{
    std::fstream stream1;
    std::fstream stream2;
    stream1.open(datei1.c_str());
    stream2.open(datei2.c_str());

    if (!stream1.good())
        throw std::invalid_argument("Datei" + datei1 + " ist Fehlerhaft...");
    if (!stream2.good())
        throw std::invalid_argument("Datei" + datei2 + " ist Fehlerhaft...");

    while (!stream1.eof())
    {
        Messung m;
        stream1>>m;
        m.SetOrt("Frankfurt Brudi");
        ffmmap.insert(std::pair<Zeitpunkt, Messung>(m.GetZeitpunkt(), m));
        ffmvec.push_back(m);
    }

    while (!stream2.eof())
    {
        Messung m;
        stream2>>m;
        m.SetOrt("Hamburg");
        hhvec.push_back(m);
        hhmmap.insert(std::pair<Zeitpunkt, Messung>(m.GetZeitpunkt(), m));
    }
    //    for (auto elem : ffmvec)
    //    {
    //      std::  cout<<elem<<std::endl;
    //    }

}

//Wetterdienst::Wetterdienst(const Wetterdienst& orig)
//{
//}

Wetterdienst::~Wetterdienst()
{
}

void Wetterdienst::Aufgabe4a()
{

    struct Info
    {
        Zeitpunkt z;
        double tmp;

        bool operator<(const Info& rechts)
        {
            return tmp > rechts.tmp;
        }
    };
    
    
    std::list<Info>temps;
    Info t;
    double counter = 0;
    double sum = 0;
    for(auto elem : ffmvec)
    {
        if (counter == 0)
        {
            t.z = elem.m_zeitpunkt;
        }
        t.tmp += elem.m_temp;
        counter++;
        if (counter == 24)
        {
            t.tmp=t.tmp / counter;
            temps.push_back(t);
            counter = 0;
        }

    }

    temps.sort();
    int x;
    for (auto elem : temps)
    {
        std::cout<<elem.z<<": "<<elem.tmp<<std::endl;
      
    }


}

void Wetterdienst::Aufgabe4b()
{
    struct diff{
        diff(double ffm,double hh){
            differenz=ffm-hh;
        };
        double differenz;
        
        bool operator<(const diff& rechts){
            return differenz>rechts.differenz;
        }
    };
    
    std::vector<diff>d;
   
    for (int i = 0; i < ffmvec.size(); i++)
    {
       
        d.push_back(diff(ffmvec[i].m_temp,hhvec[i].m_temp));
    }
    
    std::sort(d.begin(),d.end());
    
    for (int i = 0; i < 5; i++)
    {
        std::cout<<d[i].differenz<<std::endl;

    }

}

void Wetterdienst::Aufgabe4c()
{

    double counter[3];
    double sum[3];
    
   for (int i = 0; i < 3; i++)
    {
       counter[i]=0;
       sum[i]=0;

    }
 
    for (auto elem : ffmvec)
    {
        if (elem.m_zeitpunkt.getJahr() == 2010)
        {
            counter[0]++;
            sum[0] += elem.m_temp;
        }
        else if (elem.m_zeitpunkt.getJahr() == 2011)
        {
            counter[1]++;
            sum[1] += elem.m_temp;
        }
        else if (elem.m_zeitpunkt.getJahr() == 2012)
        {
            counter[2]++;
            sum[2] += elem.m_temp;
        }
        
    }
    for (int i = 0; i < 3; i++)
    {
    sum[i] = sum[i] / counter[i];
    }
    
              std::ofstream output; //output dann anstatt cout...
          output.open("text.txt");
          
    output << "Frankfurt jahresdurchschnitt 2010: " << sum[0] << std::endl;
       output << "Frankfurt jahresdurchschnitt 2011: " << sum[1] << std::endl;
          output << "Frankfurt jahresdurchschnitt 2012: " << sum[2] << std::endl;
  
          
           for (int i = 0; i < 3; i++)
    {
       counter[i]=0;
       sum[i]=0;

    }
    for (auto elem : hhvec)
    {
        if (elem.m_zeitpunkt.getJahr() == 2010)
        {
            counter[0]++;
            sum[0] += elem.m_temp;
        }
        else if (elem.m_zeitpunkt.getJahr() == 2011)
        {
            counter[1]++;
            sum[1] += elem.m_temp;
        }
        else if (elem.m_zeitpunkt.getJahr() == 2012)
        {
            counter[2]++;
            sum[2] += elem.m_temp;
        }
        
    }
    for (int i = 0; i < 3; i++)
    {
    sum[i] = sum[i] / counter[i];
    }
    output << "Hamburg jahresdurchschnitt 2010: " << sum[0] << std::endl;
      output << "Hamburg jahresdurchschnitt 2011: " << sum[1] << std::endl;
          output << "Hamburg jahresdurchschnitt 2012: " << sum[2] << std::endl;
    
  
          
}

void Wetterdienst::Aufgabe4d()
{

    struct Info
    {
        std::string stadt;
        double tmp;

        bool operator<(const Info& rechts)
        {
            return tmp > rechts.tmp;
        }

    };

    std::vector<Info>maxtmp;

    for (auto elem : ffmvec)
    {
        if (elem.m_zeitpunkt.getStunde() == 12)
        {
            Info i;
            i.stadt = "Frankfurt: ";
            i.tmp = elem.m_temp;
            maxtmp.push_back(i);
        }
    }

    for (auto elem : hhvec)
    {
        if (elem.m_zeitpunkt.getStunde() == 12)
        {
            Info i;
            i.stadt = "Hamburg: ";
            i.tmp = elem.m_temp;
            maxtmp.push_back(i);


        }
    }
    std::sort(maxtmp.begin(), maxtmp.end());
    int counter = 0;
    for (int i = 0; i < maxtmp.size() && i < 100; i++)
    {


        std::cout << maxtmp[i].stadt << maxtmp[i].tmp << std::endl;
        if (maxtmp[i].stadt == "Hamburg: ")
            counter++;

    }
    std::cout << counter << "% der temp kommen aus HH" << std::endl;




}

void Wetterdienst::Aufgabe4e()
{
    int monat, jahr;
    std::cout << "geben sie bitte Jahr und Monat ein.." << std::endl;
    std::cin>>monat;
    std::cin>>jahr;
    if (monat < 1 || monat > 12)
        throw std::invalid_argument("Es gibt nur Monate von 1-12 du nase...");
    if (jahr < 2000 || jahr > 2011)
        throw std::invalid_argument("Nur daten von den Jahren 2000-2011 bekannt");

    double sum = 0;
    double counter = 0;
    for (auto elem : ffmvec)
    {
        if (elem.m_zeitpunkt.getJahr() == jahr && elem.m_zeitpunkt.getMonat() == monat)
        {
            sum += elem.m_temp;
            counter++;
        }
    }
    std::cout << "Monatsdurchschnitt für " << monat << "." << jahr << " ist:" << std::endl << "Frankfurt: " << sum / counter << std::endl;
    sum = 0;
    counter = 0;
    for (auto elem : hhvec)
    {
        if (elem.m_zeitpunkt.getJahr() == jahr && elem.m_zeitpunkt.getMonat() == monat)
        {
            sum += elem.m_temp;
            counter++;
        }
    }
    std::cout << "Hamburg: " << sum / counter << std::endl;
}

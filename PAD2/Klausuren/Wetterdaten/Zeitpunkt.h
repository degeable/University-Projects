/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Zeitpunkt.h
 * Author: stud
 *
 * Created on 10. Juli 2017, 11:22
 */

#ifndef ZEITPUNKT_H
#define ZEITPUNKT_H
#include <string>
#include <sstream>
#include <iostream>

class Zeitpunkt
{
public:
    Zeitpunkt(const std::string& datetime);
    
    Zeitpunkt();
    
    friend std::istream& operator>>(std::istream& is, Zeitpunkt& obj);

    friend std::ostream& operator<<(std::ostream& os, const Zeitpunkt& obj);

    
    bool operator>(const Zeitpunkt& right) const;

    bool operator<(const Zeitpunkt& right) const;

  void getTag();
    
  struct VergleicheBisTag
	{

		bool operator()(const Zeitpunkt& links, const Zeitpunkt& rechts)
		{
			if (links.m_jahr != rechts.m_jahr)
				return links.m_jahr < rechts.m_jahr;
			if (links.m_monat != rechts.m_monat)
				return links.m_monat < rechts.m_monat;
			return links.m_tag < rechts.m_tag;
		}
	};
        
    virtual ~Zeitpunkt();
        void setStunde(int Stunde);
        int getStunde() const;
        int getMonat() const;
        int getJahr() const;
private:
    int m_jahr;
    int m_monat;
    int m_tag;
    int m_Stunde;
};

#endif /* ZEITPUNKT_H */


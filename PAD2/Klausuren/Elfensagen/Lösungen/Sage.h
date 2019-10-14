/* 
 * File:   Sage.h
 * Author: Michael Roth
 *
 * Created on 21. September 2015, 11:45
 */

#ifndef SAGE_H
#define	SAGE_H
#include "Word.h"
//#include <list>
#include <string>
#include <map>
#include <set>

class Tale
{
public:
	Tale(const std::string& fname);
	virtual ~Tale();
	
	//Einfach alle Woerter nach Alphabet ausgeben, Nomen mit Zeilen und
	// Orte mit Koordinaten
	void aufgabe1() const;
	
	//Alle Woerter sortiert nach Häufigkeit ausgeben
	void aufgabe2() const;
	
	//Nur Nomen (und damit auch Orte) sortiert nach Häufigkeit ausgeben
	void aufgabe3() const;
	
	void aufgabe() const;

private:

	struct PlaceLookup
	{
		std::string name;
		double latitude;
		double longitude;
	};

	std::map<std::string, PlaceLookup> m_places;
	std::set<Word*, Word::SortByName> m_words;
	
	std::multimap<std::string, Word*> m_words2;

	std::string filter(const std::string& in) const;
	bool isPlace(const std::string& in) const;
};

#endif	/* SAGE_H */


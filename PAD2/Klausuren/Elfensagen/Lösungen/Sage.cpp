/* 
 * File:   Sage.cpp
 * Author: Michael Roth
 * 
 * Created on 21. September 2015, 11:45
 */

#include "Sage.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <locale>
#include <sstream>
#include <list>

Tale::Tale(const std::string& fname)
{
	using namespace std;
	ifstream file(fname.c_str());
	if (!file.good())
		throw runtime_error("File could not be opened!");

	ifstream places("places.txt");
	if (!places.good())
		throw runtime_error("Place Database not found!");

	if (!setlocale(LC_CTYPE, "de_DE"))
		throw runtime_error("Unable to set locale");

	//read places
	while (!places.eof())
	{
		PlaceLookup p;
		places >> p.name >> p.latitude >> p.longitude;
		m_places.insert(make_pair(p.name, p));
	}

	string tmp;
	int linecounter = 0;

	while (!file.eof())
	{
		//does the line counting magic
		linecounter++;
		getline(file, tmp);
		stringstream str;
		str.str(tmp);

		while (!str.eof())
		{
			str >> tmp;
			//linecounter++;

			tmp = filter(tmp);
			if (tmp.empty())
				continue;

			Word* word;
			if (islower(tmp[0]))
			{
				word = new Word(tmp);
			}
			else if (isPlace(tmp))
			{
				word = new Place(tmp, m_places[tmp].latitude, m_places[tmp].longitude);
			}
			else
			{
				word = new Noun(tmp);
			}

			//cout << *word << endl;
			auto it = m_words.insert(word);
			if (!it.second)
				(**it.first)++;

			Noun* nounOrPlace = dynamic_cast<Noun*> (*it.first);
			if (nounOrPlace != nullptr)
			{
				nounOrPlace->addLine(linecounter);
			}

		}
	}
	cout << endl;
}

bool Tale::isPlace(const std::string& in) const
{
	if (m_places.find(in) != m_places.end())
		return true;
	return false;
}

std::string Tale::filter(const std::string& in) const
{
	std::string tmp;
	for (const auto& c : in)
	{
		if (std::isalpha(c))
			tmp.push_back(c);
	}
	return tmp;
}

Tale::~Tale()
{
}

void Tale::aufgabe1() const
{
	using namespace std;
	for (const auto& w : m_words)
	{
		cout << *w << endl;
	}
}

void Tale::aufgabe2() const
{
	using namespace std;
	list<Word*> words(m_words.begin(), m_words.end());
	words.sort(Word::SortByOccurance());
	for (const auto& w : words)
	{
		cout << *w << endl;
	}
}

void Tale::aufgabe3() const
{
	using namespace std;
	list<Noun*> nouns;
	for (auto it = m_words.begin(); it != m_words.end(); it++)
	{
		Noun* n = dynamic_cast<Noun*> (*it);
		if (n != nullptr)
			nouns.push_back(n);
	}
	nouns.sort(Word::SortByOccurance());
	
	for(const auto& n : nouns)
	{
		n->print(cout);
		cout << endl;
	}
	
}

void Tale::aufgabe() const
{
	
}






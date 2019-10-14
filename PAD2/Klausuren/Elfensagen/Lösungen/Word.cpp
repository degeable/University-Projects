/* 
 * File:   Word.cpp
 * Author: Michael Roth
 * 
 * Created on 21. September 2015, 11:45
 */

#include "Word.h"

Word::Word(std::string word) :
m_occ(1), m_word(word)
{
}

Word::Word(const Word& w) : m_occ(w.m_occ), m_word(w.m_word)
{
}

Word::~Word()
{

}

std::ostream& operator<<(std::ostream& os, const Word& obj)
{
	obj.print(os);
	return os;
}

void Word::print(std::ostream& os) const
{
	os << "Word: " << m_word << "(" << m_occ << ")";
}


//*******************************************************************+

Noun::Noun(std::string word) :
Word(word)
{
}

Noun::Noun(const Noun& n) : Word(n), m_lines(n.m_lines)
{
}

Noun::~Noun()
{

}

void Noun::addLine(int line)
{
	m_lines.push_back(line);
}

void Noun::print(std::ostream& os) const
{
	os << "Noun: " << m_word << "(" << m_occ << ")";
	if (m_lines.empty())
		return;
	os << ": ";
	auto it = m_lines.begin();
	if (it == m_lines.end())
		return;
	os << *it;
	it++;
	while (it != m_lines.end())
	{
		os << ", " << *it;
		it++;
	}

}


//*******************************************************************+

Place::Place(std::string word, double latitude, double longitude) :
Noun(word), m_lat(latitude), m_long(longitude)
{
}

Place::Place(const Place& p) : Noun(p), m_lat(p.m_lat), m_long(p.m_long)
{

}

Place::~Place()
{

}

void Place::print(std::ostream& os) const
{
	os << "Place: " << m_word << "(" << m_occ << ")" << "@ " << m_lat << " / " << m_long;
	if (m_lines.empty())
		return;
	os << ": ";
	auto it = m_lines.begin();
	if (it == m_lines.end())
		return;
	os << *it;
	it++;
	while (it != m_lines.end())
	{
		os << ", " << *it;
		it++;
	}
}


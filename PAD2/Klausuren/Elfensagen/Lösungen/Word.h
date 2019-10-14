/* 
 * File:   Word.h
 * Author: Michael Roth
 *
 * Created on 21. September 2015, 11:45
 */

#ifndef WORD_H
#define	WORD_H
#include <string>
#include <list>
#include <iostream>

class Word
{
public:
	Word(std::string word);
	Word(const Word& w);
	friend std::ostream& operator<<(std::ostream& os, const Word& obj);
	virtual void print(std::ostream& os) const;
	virtual ~Word();

	virtual Word operator++(int)
	{
		m_occ++;
		return *this;
	}

	struct SortByName
	{

		bool operator()(const Word* lhs, const Word* rhs)
		{
			return lhs->m_word < rhs->m_word;
		}
	};

	struct SortByOccurance
	{

		bool operator()(const Word* lhs, const Word* rhs)
		{
			if (lhs->m_occ == rhs->m_occ)
				return lhs->m_word < rhs->m_word;
			else
				return lhs->m_occ > rhs->m_occ;
		}
	};


protected:
	long m_occ;
	std::string m_word;

};

class Noun : public Word
{
public:
	Noun(std::string word);
	Noun(const Noun& n);
	void addLine(int line);
	friend std::ostream& operator<<(std::ostream& os, const Noun& obj);
	virtual void print(std::ostream& os) const;
	virtual ~Noun();



protected:
	std::list<int> m_lines;
};

class Place : public Noun
{
public:
	Place(std::string word, double latitude, double longitude);
	Place(const Place& p);
	friend std::ostream& operator<<(std::ostream& os, const Place& obj);
	virtual void print(std::ostream& os) const;
	virtual ~Place();

private:
	double m_lat;
	double m_long;
};



#endif	/* WORD_H */


/* 
 * File:   DynArray.h
 * Author: Michael Roth
 *
 * Created on 27. November 2014, 12:55
 */

#ifndef DYNARRAY_H
#define	DYNARRAY_H
#include "lied.h"
#include <iostream>
using namespace std;
class lied;

class DynArray
{
public:
	DynArray(); //Standardkonstruktor
	DynArray(int newCapacity); //Weiterer Konstruktor
	~DynArray(); //Destruktor, muss implementiert werden

	lied& at(int index);

        void push_back(lied song);
	void pop_back();
	void erase(int index);

	int size();
	int capacity();

	void print();

private:
	void resize(int newCapacity);
	DynArray(const DynArray& other); //Kopierkonstruktor soll explizit *nicht* aufgerufen werden
	lied* m_data;
	int m_size;
	int m_capacity;
};



#endif	/* DYNARRAY_H */

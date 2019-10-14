#include <cstdlib>
#include <iostream>
#include <string>
#include "DynArray.h"
#include "lied.h"


using namespace std;


DynArray::DynArray() { //Erzeug ein Array der größe 0 mit Kapazität 2

    m_data = new lied[2];
    m_size = 0;
    m_capacity = 2;
}

DynArray::DynArray(int newCapacity) { //Erzeugt ein Array  größe 0 mit Kapazität newCapacity

    m_data = new lied[newCapacity];
    m_size = 0;
    m_capacity = newCapacity;

}

DynArray::~DynArray() { //Destruktor, setzt Größe und Kapazität auf 0 und den Pointer auf NULL
    delete [] m_data;
    m_capacity = 0;
    m_size = 0;
    m_data = NULL;
}

lied&DynArray::at(int index) { //gibt m_data am angeforderten Index zurück
    return m_data[index];
}

int DynArray::capacity() { //gibt die aktuelle Kapazität zurück
    return m_capacity;
}

int DynArray::size() { //gibt die aktuelle größe zurück
    return m_size;
}

void DynArray::print() { // gibt den inhalt des Arrays aus

    for (int i = 0; i < m_size; i++) {
        m_data[i].showDetails();
    }
}

void DynArray::resize(int newCapacity) { //ändert die Kapazität 
    lied* new_m_data;
    new_m_data = new lied[newCapacity]; //fehler wenn mit Konstruktor gemacht
    for (int i = 0; i < m_size; i++) {
        new_m_data[i] = m_data[i];
    }
    delete [] m_data;
    m_data = new_m_data;
    m_capacity = newCapacity;
    m_size = m_size;
}

void DynArray::push_back(lied song) { //wenn die Kapazität erreicht wird, vergrößert diese sich um den faktor 2
    if (m_size == m_capacity) {
        resize(2 * m_capacity);
        m_data[m_size] = song;
    } else
     m_data[m_size] = song;
    m_size++;

}

void DynArray::pop_back() { //löscht die letzte stelle aus dem Array
    m_size = m_size -1;
    lied* new_m_da;
    new_m_da = new lied[m_capacity];
    for (int i = 0; i < m_size; i++) {
        new_m_da[i] = m_data[i];
    }
    
    delete [] m_data;
    m_data = new_m_da;
    m_capacity = m_capacity;
}



void DynArray::erase(int index) { //"löscht" eine Stelle und verschiebt die restlichen Einträge um eine Stelle nach Links
    for (int i = index; i < m_size - 1; i++) {
        m_data[i] = m_data[i + 1];
    }
    pop_back();
}
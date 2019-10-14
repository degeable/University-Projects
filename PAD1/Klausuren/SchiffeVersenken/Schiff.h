/* 
 * File:   Schiff.h
 * Author: fs
 *
 * Created on 4. Februar 2017, 09:58
 */

#ifndef SCHIFF_H
#define	SCHIFF_H
#include <iostream>
#include <vector>

using namespace std;

enum Status {
    UNBESCHAEDIGT, GETROFFEN, VERSENKT
};

enum Ausrichtung {
    NORD, OST, SUED, WEST
};

class Schiffsteil {
public:
    Schiffsteil(int reihe, int spalte, Status status);

    void SetStatus(Status status) {
        m_status = status;
    }

    Status GetStatus() const {
        return m_status;
    }

    int GetSpalte() const {
        return m_spalte;
    }

    int GetReihe() const {
        return m_reihe;
    }

private:
    int m_reihe;
    int m_spalte;
    Status m_status;
};

class Schiff {
public:
    Schiff(int laenge, int reihe, int spalte, Ausrichtung ausrichtung);
    // Schiff(const Schiff& orig);
    virtual ~Schiff();
    bool beschuss(int reihe, int spalte);
    bool belegt(int reihe, int spalte);
    void Zeichne(char leinwand[11][11]);

private:
    int m_laenge;
    vector<Schiffsteil>m_teile;
};



#endif	/* SCHIFF_H */


/* 
 * File:   lied.h
 * Author: fs
 *
 * Created on 24. November 2016, 17:19
 */

#include <vector>
#include <string>

using namespace std;

enum Genre {
    Rock, Pop, Klassik, HardRock, Techno, HipHop, Jazz
};

class lied {
public:
    lied();
    void setNew(string titel, string interpret, string jahr, string laenge, string Genre);
    void showDetails();
    void setTitel();
    void setInterpret();
    void setErscheinungsjahr();
    void setLaenge();
    void setGenre();
    string getTitel();
    void printTitel(vector<lied> &song);
private:
    string Titel;
    string Interpret;
    string Erscheinungsjahr;
    string Laenge;
    Genre genre;
};

/* LIED_H */


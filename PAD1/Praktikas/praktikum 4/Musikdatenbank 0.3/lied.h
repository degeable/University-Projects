/* 
 * File:   lied.h
 * Author: fs
 *
 * Created on 24. November 2016, 17:19
 */

#include <vector>
#include <string>

using namespace std;



class lied {
public:

    void setNew(string titel, string interpret, string jahr, string laenge, string Genre);
    void showDetails();
    void setTitel();
    void setInterpret();
    void setErscheinungsjahr();
    void setLaenge();
    void setGenre();
    string getTitel();
    //int printTitel();
private:
    enum Genre {
    Rock, Pop, Klassik, HardRock, Techno, HipHop, Jazz
};
    string Titel;
    string Interpret;
    string Erscheinungsjahr;
    string Laenge;
    Genre genre;
};
void Neu(vector<lied>&song);
void save(vector<lied>&song, lied entry);
int menue(vector<lied>&song);
void Alle(vector<lied>&song);
void Anzeigen(vector<lied>&song);
void loeschen(vector<lied>&song);
void bearbeiten(vector<lied>&song);
/* LIED_H */


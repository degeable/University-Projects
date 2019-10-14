#include <iostream>
#include <string>
#include <vector> 
#include "class.h"
using namespace std;

vector<lied>song;

enum Genre {
    Rock, Pop, Klassik, HardRock, Techno, HipHop, Jazz
};

class lied {
public:
    string Titel;
    string Interpret;
    int Erscheinungsjahr;
    string Laenge;
    Genre genre;
};

void bearbeiten() {
    int nr = song.size();
    nr--;
    int titel;
    int gnr;
    char info;
    cout << "welchen Titel wollen sie löschen? Es sind 0-" << nr << " Titel vorhanden \n \n";
    cin>>titel;
    cout << "welche Information wollen sie bearbeiten?" << endl;
    cout << "1.(T)itel\n 2.(I)nterpret \n 3. (E)rscheingungsjahr \n 4. (L)aenge \n 5. (G)enre" << endl;
    cin>>info;
    if (info == '1' || info == 'T' || info == 't') {
        cout <<"Bitte geben sie ein neuen Titel ein \n";
        cin >> song[titel].Titel;
    } else if (info == '2' || info == 'I' || info == 'i') {
        cout <<"Bitte geben sie ein neuen Interpret ein \n";
        cin >> song[titel].Interpret;
    } else if (info == '3' || info == 'E' || info == 'e') {
        cout <<"Bitte geben sie ein neues Erscheinungsjahr ein \n";
        cin >> song[titel].Erscheinungsjahr;
    } else if (info == '4' || info == 'L' || info == 'l') {
        cout <<"Bitte geben sie eine neue Laenge ein \n";
        cin >> song[titel].Laenge;
    } else if (info == '5' || info == 'G' || info == 'g') {
        cout <<"Bitte geben sie ein neues Genre ein \n";
        cin >> song[titel].Erscheinungsjahr;
        song[titel].genre = (Genre) gnr;
    }

    }

    void loeschen() {
        int nr = song.size();
        nr--;
        int titel;
        cout << "welchen Titel wollen sie löschen? Es sind 0-" << nr << " Titel vorhanden \n";
        cin>>titel;
        song.erase(song.begin() + titel);
    }

    void Neu() {

        int gnr;
        song.push_back(lied());
        int i;
        i = song.size();
        i--;
        cout << "Geben sie den Titel ein" << endl;
        cin >> song[i].Titel;
        cout << "Geben sie den Interpret ein" << endl;
        cin >> song[i].Interpret;
        cout << "Geben sie das Erscheinungsjahr ein" << endl;
        cin >> song[i].Erscheinungsjahr;
        cout << "Geben sie die Laenge ein" << endl;
        cin >> song[i].Laenge;
        cout << "Geben sie das Genre ein (0=Rock,1=Pop,2=Klassik,3=HardRock,4=Techno,5=HipHop,6=Jazz)" << endl;
        cin >> gnr;
        song[i].genre = (Genre) gnr;
        //   switch (gnr){
        //    case 0: song[nr].genre = Rocke
        //  }



    }

    void Anzeigen() {
        int e;
        int size = song.size();
        size--;
        cout << "Welchen Eintrag wollen sie sehen?Es sind 0-" << size << "Einträge vorhanden" << endl;
        cin>>e;
        cout << "Titel: " << song[e].Titel << endl;
        cout << "Interpret: " << song[e].Interpret << endl;
        cout << "Erscheingungsjahr: " << song[e].Erscheinungsjahr << endl;
        cout << "Laenge: " << song[e].Laenge << endl;
        switch (song[e].genre) {
            case Rock: cout << "Genre: Rock" << endl << endl;
                break;
            case Pop: cout << "Genre: Pop" << endl << endl;
                break;
            case Klassik: cout << "Genre: Klassik" << endl << endl;
                break;
            case HardRock: cout << "Genre: HardRock" << endl << endl;
                break;
            case Techno: cout << "Genre: Techno" << endl << endl;
                break;
            case HipHop: cout << "Genre: Hiphop" << endl << endl;
                break;
            case Jazz: cout << "Genre: Jazz" << endl << endl;
                break;
        }
    }

    void Alle() {
        int i;
        int size = song.size();
        size--;

        for (i = 0; i <= size; i++) {
            cout << "Titel: " << song[i].Titel << endl;
            cout << "Interpret: " << song[i].Interpret << endl;
            cout << "Erscheinungsjahr: " << song[i].Erscheinungsjahr << endl;
            cout << "Laenge: " << song[i].Laenge << endl;
            switch (song[i].genre) {
                case Rock: cout << "Genre: Rock" << endl << endl;
                    break;
                case Pop: cout << "Genre: Pop" << endl << endl;
                    break;
                case Klassik: cout << "Genre: Klassik" << endl << endl;
                    break;
                case HardRock: cout << "Genre: HardRock" << endl << endl;
                    break;
                case Techno: cout << "Genre: Techno" << endl << endl;
                    break;
                case HipHop: cout << "Genre: Hiphop" << endl << endl;
                    break;
                case Jazz: cout << "Genre: Jazz" << endl << endl;
                    break;
            }
        }

    }

    int menue() {



        char Eingabe = 'z'; // char ...
        while (Eingabe != '0') {

            cout << "***********Musikbilbiothek Version 0.3**********" << endl;
            cout << "Hauptmenue:" << endl;
            cout << "1. (N)euen Eintrag anlegen" << endl;
            cout << "2. (D)etails eines Eintrages anzeigen" << endl;
            cout << "3. Einen Eintrag (l)oeschen" << endl;
            cout << "4. Einen Eintrag (b)earbeiten" << endl;
            cout << "5. Einen Eintrag (s)uchen" << endl;
            cout << "6. (A)lle Eintraege anzeigen" << endl;
            cout << "0. Programm beenden" << endl;


            cout << "was möchten Sie tun?";
            cin >> Eingabe;



            if (Eingabe == '1' || Eingabe == 'N' || Eingabe == 'n') {
                cout << "Neuer Eintrag ausgewählt(Nr." << song.size() << ")" << endl;
                Neu();

            } else if (Eingabe == '2' || Eingabe == 'D' || Eingabe == 'd') {

                cout << "Details anzeigen ausgewählt" << endl;
                Anzeigen();

            } else if (Eingabe == '3' || Eingabe == 'L' || Eingabe == 'l') {

                cout << "Datei löschen ausgewählt" << endl;
                loeschen();
            } else if (Eingabe == '4' || Eingabe == 'b' || Eingabe == 'B') {

                cout << "Eintrag bearbeiten ausgewählt" << endl;
                bearbeiten();
            } else if (Eingabe == '5' || Eingabe == 'S' || Eingabe == 's') {

                cout << "Eintrag suchen ausgewählt" << endl;
                //Funktion noch nicht Implementiert
            } else if (Eingabe == '6' || Eingabe == 'a' || Eingabe == 'A') {

                cout << "Alle Einträge anzeigen ausgewählt" << endl << endl;
                Alle();
            } else if (Eingabe == '0') {

                cout << "Programm beenden ausgewählt" << endl;
                return 0; //Beendet das Programm

            } else
                cout << "Falsche Eingabe" << endl;

        }

    }

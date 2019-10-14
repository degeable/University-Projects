#include <cstdlib>
#include <iostream>
#include "lied.h"
#include <string>
#include <vector>

using namespace std;

string lied::getTitel() {
    return Titel;

}

void lied::setNew(string titel, string interpret, string jahr, string laenge, string richtung) {
    Titel = titel;
    Interpret = interpret;
    Erscheinungsjahr = jahr;
    Laenge = laenge;
    if ((richtung == "Rock") || (richtung == "rock")) {
        genre = Rock;
    } else if ((richtung == "Pop") || (richtung == "pop")) {
        genre = Pop;
    } else if ((richtung == "Klassik") || (richtung == "klassik")) {
        genre = Pop;
    } else if ((richtung == "HardRock") || (richtung == "hardrock")) {
        genre = Pop;
    } else if ((richtung == "Techno") || (richtung == "techno")) {
        genre = Pop;
    } else if ((richtung == "HipHop") || (richtung == "hiphop")) {
        genre = Pop;
    } else if ((richtung == "Jazz") || (richtung == "jazz")) {
        genre = Pop;
    }
}

void lied::setTitel() {
    string input;
    cout << "Bitte geben sie ein neuen Titel ein \n";
    cin>>input;
    Titel = input;
}

void lied::setInterpret() {
    string input;
    cout << "Bitte geben sie ein neuen Interpret ein \n";
    cin>>input;
    Interpret = input;
}

void lied::setErscheinungsjahr() {
    string input;
    cout << "Bitte geben sie ein neues Erscheinungsjahr ein \n";
    cin>>input;
    Erscheinungsjahr = input;
}

void lied::setLaenge() {
    string input;
    cout << "Bitte geben sie ein neue Laenge ein \n";
    cin>>input;
    Laenge = input;
}

void lied::setGenre() {
    string richtung;
    cout << "Bitte geben sie ein neues Genre ein \n";
    cin>>richtung;
    if ((richtung == "Rock") || (richtung == "rock")) {
        genre = Rock;
    } else if ((richtung == "Pop") || (richtung == "pop")) {
        genre = Pop;
    } else if ((richtung == "Klassik") || (richtung == "klassik")) {
        genre = Pop;
    } else if ((richtung == "HardRock") || (richtung == "hardrock")) {
        genre = Pop;
    } else if ((richtung == "Techno") || (richtung == "techno")) {
        genre = Pop;
    } else if ((richtung == "HipHop") || (richtung == "hiphop")) {
        genre = Pop;
    } else if ((richtung == "Jazz") || (richtung == "jazz")) {
        genre = Pop;
    }

}

void bearbeiten(vector<lied> &song) {
    char info;
    int i;
    int titel;
    int x = song.size();
    string Titel;
    cout << "Es sind folgende  Einträge vorhanden:" << endl;

    for (i = 0; i < x; i++) {
        Titel = song[i].getTitel();
        cout << "Nr." << i << " " << Titel << endl;
    }


    cout << "Bitte wählen sie eine Nummer um einen Eintrag zu bearbeiten.\n";
    cin>>titel;

    cout << "welche Information wollen sie bearbeiten?" << endl;
    cout << "1.(T)itel\n 2.(I)nterpret \n 3. (E)rscheingungsjahr \n 4. (L)aenge \n 5. (G)enre" << endl;
    cin>>info;
    if (info == '1' || info == 'T' || info == 't') {
        song[titel].setTitel();
    } else if (info == '2' || info == 'I' || info == 'i') {
        song[titel].setInterpret();
    } else if (info == '3' || info == 'E' || info == 'e') {
        song[titel].setErscheinungsjahr();
    } else if (info == '4' || info == 'L' || info == 'l') {
        song[titel].setLaenge();
    } else if (info == '5' || info == 'G' || info == 'g') {
        song[titel].setGenre();
    }

}

/*int lied::printTitel(){
    int i;
    int titel;
    int x = song.size();
    string Titel;
    cout << "Es sind folgende  Einträge vorhanden:" << endl;
   
    for (i = 0; i < x; i++) {
        Titel = song[i].getTitel();
        cout << "Nr." << i << " " << Titel << endl;
        return Titel;

    }
 */
void loeschen(vector<lied>&song) {
    int i;
    int titel;
    int x = song.size();
    string Titel;
    cout << "Es sind folgende  Einträge vorhanden:" << endl;

    for (i = 0; i < x; i++) {
        Titel = song[i].getTitel();
        cout << "Nr." << i << " " << Titel << endl;
    }
    cout << "Welchen Eintrag wollen sie löschen?" << endl;
    cin>>titel;
    song.erase(song.begin() + titel);
    cout << "Eintrag erfolgreich gelöscht";
}

void Neu(vector<lied>&song) {

    string titel, interpret, jahr, laenge, Genre;
    int i;
    lied entry;


    cout << "Geben sie den Titel ein" << endl;
    cin >> titel;
    cout << "Geben sie den Interpret ein" << endl;
    cin >> interpret;
    cout << "Geben sie das Erscheinungsjahr ein" << endl;
    cin >> jahr;
    cout << "Geben sie die Laenge ein" << endl;
    cin >> laenge;
    cout << "Geben sie das Genre ein (Rock,Pop,Klassik,HardRock,Techno,HipHop,Jazz)" << endl;
    cin >> Genre;


    entry.setNew(titel, interpret, jahr, laenge, Genre);
    song.push_back(entry);

}

void lied::showDetails() {
    cout << "Titel: " << Titel << endl;
    cout << "Interpret: " << Interpret << endl;
    cout << "Erscheinungsjahr: " << Erscheinungsjahr << endl;
    cout << "Laenge: " << Laenge << endl;
    switch (genre) {
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


//void save(vector<lied>&song, lied& entry) {
//   song.push_back(entry);}

void Anzeigen(vector<lied>&song) {
    int e;
    int i;
    string Titel;
    cout << "Es sind folgende  Einträge vorhanden:" << endl;
    int x = song.size();
    for (i = 0; i < x; i++) {
        Titel = song[i].getTitel();
        cout << "Nr." << i << " " << Titel << endl;

    }
    cout << "Bitte wählen sie eine Nummer um Details anzuzeigen.\n";
    cin>>e;
    song[e].showDetails();

}

void Alle(vector<lied>&song) {
    int i;
    int size = song.size();
    size--;

    for (i = 0; i <= size; i++) {
        song[i].showDetails();

    }

}

int menue(vector<lied>&song) {



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
            Neu(song);

        } else if (Eingabe == '2' || Eingabe == 'D' || Eingabe == 'd') {

            cout << "Details anzeigen ausgewählt" << endl;
            Anzeigen(song);

        } else if (Eingabe == '3' || Eingabe == 'L' || Eingabe == 'l') {

            cout << "Datei löschen ausgewählt" << endl;
            loeschen(song);
        } else if (Eingabe == '4' || Eingabe == 'b' || Eingabe == 'B') {

            cout << "Eintrag bearbeiten ausgewählt" << endl;
            bearbeiten(song);
        } else if (Eingabe == '5' || Eingabe == 'S' || Eingabe == 's') {

            cout << "Eintrag suchen ausgewählt" << endl;
            //Funktion noch nicht Implementiert
        } else if (Eingabe == '6' || Eingabe == 'a' || Eingabe == 'A') {

            cout << "Alle Einträge anzeigen ausgewählt" << endl << endl;
            Alle(song);
        } else if (Eingabe == '0') {

            cout << "Programm beenden ausgewählt" << endl;
            return 0; //Beendet das Programm

        } else
            cout << "Falsche Eingabe" << endl;

    }
}


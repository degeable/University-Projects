//Musikdatenbank 0.2

#include <iostream>
#include <string>
#include <vector> 
using namespace std;

int nr = 0;

enum Genre {
    Rock, Pop, Klassik, HardRock, Techno, HipHop, Jazz
};

struct lied {
    string Titel;
    string Interpret;
    int Erscheinungsjahr;
    string Laenge;
    Genre genre;
};
vector<lied>song(100); // andere eingabe nehmen um auf den vectro draufzuaddieren....

void Neu() {
    int gnr;
    cout << "Geben sie den Titel ein" << endl;
    cin >> song[nr].Titel;
    cout << "Geben sie den Interpret ein" << endl;
    cin >> song[nr].Interpret;
    cout << "Geben sie das Erscheinungsjahr ein" << endl;
    cin >> song[nr].Erscheinungsjahr;
    cout << "Geben sie die Laenge ein" << endl;
    cin >> song[nr].Laenge;
    cout << "Geben sie das Genre ein (0=Rock,1=Pop,2=Klassik,3=HardRock,4=Techno,5=HipHop,6=Jazz)"<<endl;
    cin >> gnr;
    song[nr].genre = (Genre) gnr;
 //   switch (gnr){
    //    case 0: song[nr].genre = Rocke
  //  }
    nr++;


}

void Anzeigen() {
    int e;
    cout << "Welchen Eintrag wollen sie sehen?Es sind 0-" << nr - 1 << "Einträge vorhanden" << endl;
    cin>>e;
    cout <<"Titel: "<< song[e].Titel << endl;
    cout <<"Interpret: "<< song[e].Interpret << endl;
    cout <<"Erscheingungsjahr: "<< song[e].Erscheinungsjahr << endl;
    cout <<"Laenge: "<< song[e].Laenge << endl;
         switch (song[e].genre) {
            case Rock: cout << "Genre: Rock" << endl<<endl;
        break;
            case Pop: cout << "Genre: Pop" << endl<<endl;
         break;
            case Klassik: cout << "Genre: Klassik" << endl<<endl;
          break;
            case HardRock: cout << "Genre: HardRock" << endl<<endl;
           break;
            case Techno: cout << "Genre: Techno" << endl<<endl;
            break;
            case HipHop: cout << "Genre: Hiphop" << endl<<endl;
             break;
            case Jazz: cout << "Genre: Jazz" << endl<<endl;
              break;}
}

void Alle() {
    int i;
    for (i = 0; i <= nr; i++) {
        cout <<"Titel: "<< song[i].Titel << endl;
        cout <<"Interpret: "<< song[i].Interpret << endl;
        cout <<"Erscheinungsjahr: "<< song[i].Erscheinungsjahr << endl;
        cout <<"Laenge: "<< song[i].Laenge << endl;
        switch (song[i].genre) {
            case Rock: cout << "Genre: Rock" << endl<<endl;
        break;
            case Pop: cout << "Genre: Pop" << endl<<endl;
         break;
            case Klassik: cout << "Genre: Klassik" << endl<<endl;
          break;
            case HardRock: cout << "Genre: HardRock" << endl<<endl;
           break;
            case Techno: cout << "Genre: Techno" << endl<<endl;
            break;
            case HipHop: cout << "Genre: Hiphop" << endl<<endl;
             break;
            case Jazz: cout << "Genre: Jazz" << endl<<endl;
              break;}
    }

}

int menue() {



    char Eingabe = 'z'; // char ...
    while (Eingabe != '0') {

        cout << "***********Musikbilbiothek Version 0.2**********" << endl;
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
            cout << "Neuer Eintrag ausgewählt(Nr." << nr << ")" << endl;
            Neu();

        } else if (Eingabe == '2' || Eingabe == 'D' || Eingabe == 'd') {

            cout << "Details anzeigen ausgewählt" << endl;
            Anzeigen();

        } else if (Eingabe == '3' || Eingabe == 'L' || Eingabe == 'l') {

            cout << "Datei löschen ausgewählt" << endl;
            //Funktion noch nicht Implementiert
        } else if (Eingabe == '4' || Eingabe == 'b' || Eingabe == 'B') {

            cout << "Eintrag bearbeiten ausgewählt" << endl;
            //Funktion noch nicht Implementiert
        } else if (Eingabe == '5' || Eingabe == 'S' || Eingabe == 's') {

            cout << "Eintrag suchen ausgewählt" << endl;
            //Funktion noch nicht Implementiert
        } else if (Eingabe == '6' || Eingabe == 'a' || Eingabe == 'A') {

            cout << "Alle Einträge anzeigen ausgewählt" << endl<<endl;
            Alle();
        } else if (Eingabe == '0') {

            cout << "Programm beenden ausgewählt" << endl;
            return 0; //Beendet das Programm

        } else
            cout << "Falsche Eingabe" << endl;

    }

}

int main() {



    menue();
}
#include <iostream>

using namespace std;

bool choose()
{
    string e;
    
    cout<< "Was möchten sie tun? ";
    cin>> e;
   
    if (e=="1" || e=="n" || e=="N") {
        cout<<"Neuen Eintrag angelegen ausgewählt"<<endl;
    }
    else if (e=="2" || e=="d" || e=="D") {
        cout<<"Details eines Eintrages anzeigen ausgewählt"<<endl;
    }
    else if (e=="3") {
        cout<<"Einen Eintrag loeschen ausgewählt"<<endl;
    }
    else if (e=="4") {
        cout<<"Einen Eintrag bearbeiten ausgewählt"<<endl;
    }
    else if (e=="5") {
        cout<<"Einen Eintrag suchen ausgewählt"<<endl;
    }
    else if (e=="6") {
        cout<<"Alle Einträge anzeigen ausgewählt"<<endl;
    }
    else if (e == "0") {
        cout<<"Das Programm wird beendet"<<endl;
        return true;
    }
    else {
        cout<<"Falsche Eingabe"<<endl;
        return choose();
    }    
}

int menu()
{
    cout    << "*********** Musikbibliothek Version 0.1**********"
            << endl
            << "Hauptmenue:"
            << endl
            << "1. (N)euen Eintrag anlegen"
            << endl
            << "2. (D)etails eines Eintrages anzeigen"  
            << endl
            << "3. Einen Eintrag (l)oeschen"
            << endl
            << "4. Einen Eintrag (b)earbeiten"
            << endl
            << "5. Einen Eintrag (s)uchen"
            << endl
            << "6. (A)lle Eintraege anzeigen"
            << endl
            << endl
            << "0. Programm beenden"
            << endl
            << endl;
    if (choose() == true){
        return 0;
    };
    return 0;
}

int main()
{
    menu();
    return 0;
}


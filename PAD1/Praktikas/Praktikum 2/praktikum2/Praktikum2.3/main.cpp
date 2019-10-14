//Musikdatenbank 0.1

#include <iostream>
#include <string>
 
using namespace std;
 
//while schleife.... 

int menue()
{
    
    char Eingabe='z'; // char ...
    while (Eingabe != '0' ){
    
cout << "***********Musikbilbiothek Version 0.1**********"<< endl;
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
    
   

if (Eingabe=='1' ||Eingabe=='N' || Eingabe=='n' ) {
    cout << "Neuer Eintrag ausgewählt"<< endl;
    //Funktion noch nicht Implementiert
}
else if (Eingabe=='2' ||  Eingabe=='D' || Eingabe=='d'){
    
    cout << "Details anzeigen ausgewählt"<< endl;
        //Funktion noch nicht Implementiert
}
else if (Eingabe == '3' || Eingabe=='L' || Eingabe=='l'){
    
    cout << "Datei löschen ausgewählt"<< endl;
        //Funktion noch nicht Implementiert
}
else if (Eingabe =='4' || Eingabe=='b' || Eingabe=='B'){
    
    cout << "Eintrag bearbeiten ausgewählt"<< endl;
        //Funktion noch nicht Implementiert
}
else if (Eingabe == '5' || Eingabe=='S' || Eingabe=='s'){
   
    cout << "Eintrag suchen ausgewählt"<< endl;
        //Funktion noch nicht Implementiert
}
else if (Eingabe == '6' || Eingabe=='a'|| Eingabe=='A'){
    
    cout << "Alle Einträge anzeigen ausgewählt"<< endl;
        //Funktion noch nicht Implementiert
}
else if (Eingabe =='0'){
   
    cout << "Programm beenden ausgewählt"<< endl;
    return 0; //Beendet das Programm
        
}
else 
    cout<< "Falsche Eingabe"<< endl;

}
}

int main()
{

  menue();
  return 0; 
}
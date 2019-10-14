#include <cstdlib>
#include <iostream>
#include "MD_V03.h"
#include <string>
#include <vector>

using std::endl;
using std::cout;
using std::cin;



void Lied ::setSong(string title, string artist, string year, string length, Genre type){
    titel = title;
    interpret = artist;
    erscheinungsjahr = year;
    laenge = length;
    genre = type;
    }

string Lied ::titleReturn(){
    return titel;
}

string Lied ::getTitle()
{
    return titel;
}

void Lied ::printTitle(){
    cout << titel;
}

void Lied ::setTitle()
{
    string input;
    
    cout << "Neuer Titel: ";
    cin >> input;
    cout << endl;
    titel = input;
}

void Lied ::setInterpret()
{
    string input;
    
    cout << "Neuer Interpret: "; 
    cin >> input;
    cout << endl;
    interpret = input;
}

void Lied ::setYear()
{
    string input;
    
    cout << "Neues Erscheinungsjahr: " ;
    cin >> input;
    cout << endl;
    erscheinungsjahr = input;    
}

void Lied ::setLen()
{
    string input;
    
    cout << "Neue Liedlaenge: " ;
    cin >> input;
    cout << endl;
    laenge = input;   
}

void Lied ::setGenre()
{
    string input;
    
    cout << "Neues Erscheinungsjahr: " ;
    cin >> input;
    cout << endl;
    genre = stringToGenre(input);       
}

void Lied ::printDetails(){
    cout << "Titel: " << titel << endl;
    cout << "Interpret: " <<  interpret << endl;
    cout << "Erscheinungsjahr: " << erscheinungsjahr <<endl;
    cout << "Laenge: " << laenge << endl;
    cout << "Genre: " << printGenre(genre) << endl;
}

     







void menu(vector<Lied>& save){

    while(true){
        
    cout << "\n\n******** Musikbibliothem Version 0.2 ********"; 
    cout << "\n Hauptmenue:";
    cout << "\n 1. (N)euen Eintrag einlesen.";
    cout << "\n 2. (D)etails eines Eintrags anzeigen";
    cout << "\n 3. Einen Eintrag (l)oeschen";
    cout << "\n 4. Einen Eintrag (b)earbeiten";
    cout << "\n 5. Einen Eintrag (s)uchen";
    cout << "\n 6. (A)lle Eintraege anzeigen";
    cout << "\n";
    cout << "\n 0. Programm beenden" ;
    cout << "\n\n Fuehren Sie eine der hier aufgelsiteten Aktionen mittels Eingabe ";
    cout << "\n der jeweiligen Zahl oder des Buchstabens aus." << endl << endl;
    
    char user_input;
    
    cin >> user_input;
    cout << "Ihre Eingabe: " << user_input << endl; 
    
    switch(user_input){
        case ('1'):
        case ('N'):
        case ('n'): cout << "\n\nNeuen Eintrag einlesen." << endl;
                    newEntry(save); break;
        case ('2'):
        case ('D'):
        case ('d'): cout << "\n\nDetails anzeigen." << endl;
                    printShowDetails(save); break;
        case ('3'):
        case ('L'):
        case ('l'): cout << "\n\nEintrag geloescht." << endl;
                    del(save); break;
        case ('4'):
        case ('B'):
        case ('b'): cout << "\n\nEintrag bearbeiten." << endl;
                    edit(save); break;
        case ('5'):
        case ('S'):
        case ('s'): cout << "\n\nEintrag suchen." << endl;
                    continue; break;
        case ('6'):
        case ('A'):
        case ('a'): cout << "\n\nAlle Eintraege anzeigen." << endl;
                    showAllEntries(save); break;
        case ('0'): cout << "\n\nProgramm beenden." << endl;
                    continue; break;
        default: 
        {
            cout << "\n\nUngueltige Eingabe" << endl;
            continue;
        }
    }
    }
}

// Aufgabe 2
void save(vector<Lied>& save, Lied& song){
    save.push_back(song);
}



string printGenre(Genre genre){
    if(genre == Rock){
        return "Rock";
    }
    else if(genre == Pop){
        return "Pop";
    }
    else if(genre == Rapp){
        return "Rapp";
    }
    else if(genre == House){
        return "House";
    }
    else if(genre == Klassik){
        return "Klassik";
    }
}


// Neuer Eintrag
void newEntry(vector<Lied>& save_vec){
    string title, artist, year, length, type;
    Genre genre;
    Lied song;
    
    cout << "Titel: "; cin >> title;
    cout <<"\nInterpret: "; cin >> artist;
    cout <<"\nErscheinungsjahr: "; cin >> year;
    cout <<"\nLaenge: "; cin >> length;
    cout <<"\nGenre: "; cin >> type;
    if((type == "Rock") || (type == "rock"))
    {
        genre = Rock;
    }
    else if((type == "Pop") || (type == "pop"))
    {
        genre = Pop;
    }
    else if((type == "Rapp") || (type == "rapp"))
    {
        genre = Rapp;
    }
    else if((type == "House") || (type == "house"))
    {
        genre = House; 
    }
    else if((type == "Klassik") || (type == "klassik"))
    {
        genre = Klassik;
    }
    else
    {
        cout << "Dieses Genre ist in der Datenbank nicht  vorhanden." << endl;
        return;
    }
    song.setSong(title, artist, year, length, genre);
    save(save_vec, song);
}


// Details anzeigen
void listOfSongs(vector<Lied>& save)
{
    for(int i = 0; i<save.size(); i++)
    {
        cout << i + 1 << ".)" << save[i].getTitle();
        cout<< endl;
    }
}

// Überprüfe ob Titel einem Song zugeordnet werden kann
bool isTitle(vector<Lied>& save, string title)
{
    for(int i = 0; i<save.size(); i++)
    {
        if(title == save[i].titleReturn())
        {
            return true;
        }
    }
    return false;
}

void printShowDetails(vector<Lied>& save)
{
    if(!save.empty())
    {
        cout << "Waehlen Sie einen Titel aus der folgenden Liste aus. " << endl;
        listOfSongs(save);

        cout << "\nEingabe: ";
        string title;
        int counter = 0;
        cin >> title;

        cout << "\nDetails: " << endl;
        for(int i= 0; i < save.size(); i++)
        {
            if(title == save[i].titleReturn())
            {
                save[i].printDetails();
                counter++;
            }
        }
        if(counter == 0)
        {
            cout << "Der Eintrag mit dem Titel " << title << " exisitiert nicht. " <<endl;
        }
    }
    else
    {
        cout << "Die Datenbank ist leer." << endl; 
    }
    
}

void showAllEntries(vector<Lied>& save)
{
    if(!save.empty()){
        cout << "Liste aller Eintraege: " <<endl;
        listOfSongs(save);
    }
    else{
        cout << "Die Datenbank ist leer." <<endl;
    }
}

void swap(Lied& a, Lied& b)
{
    Lied tmp = a;
    a = b;
    b = tmp;
}

int select(vector<Lied>& save)
{
    while(true)
    {
        int input;
        cout << "Geben Sie eine gueltige Nummer ein, um eine Datei zu verwalten: ";
        cin >> input;

        if( (input - 1 >= 0) && (input <= save.size()) )
        {
            return input;
        }
        
        cout << "\n\nUngueltige Eigabe." << endl;
        cout << "Versuchen Sie es erneut." <<endl;
    }
  
}

void del(vector<Lied>& save)
{
    int num = select(save);
    
    if(save.size() > 1)
    {
        swap(save[num - 1], save[save.size()-1]);
        save.pop_back();
    }
    else if(save.size() == 1)
    {
        save.pop_back();
    }
    else
    {
        cout << "Die Musikdatenbank ist leer." << endl;
    }
    
    cout << "Die gewuenschte Datei wurde geloescht." << endl;
    
}

void edit(vector<Lied>& save)
{
    char input;
    int num = select(save);
    
    cout << "Was moechten sie an dem Lied: " << save[num - 1].getTitle() << " bearbeiten?" << endl;
    cout << "Folgende eingaben sing gueltig, um die jeweiligen Eintraege zu bearbeiten." << endl;
    cout << "\n Titel : t";
    cout << "\n Interpret : i";
    cout << "\n Erscheinungsjahr : e";
    cout << "\n Laenge : l";
    cout << "\n Genre : g" << endl;
    
    cin >> input;
    
    if( tolower(input) == 't')
    {
        save[num - 1].setTitle();
    }
    else if( tolower(input) == 'i' )
    {
        save[num - 1].setInterpret();
    }
    else if( tolower(input) == 'e' )
    {
        save[num - 1].setYear();
    }
    else if( tolower(input) == 'l' )
    {
        save[num - 1].setLen();
    }
    else if( tolower(input) == 'g' )
    {
        save[num - 1].setGenre();
    }
    
}


Genre stringToGenre(string type)
{
    if((type == "Rock") || (type == "rock"))
    {
        return Rock;
    }
    else if((type == "Pop") || (type == "pop"))
    {
        return Pop;
    }
    else if((type == "Rapp") || (type == "rapp"))
    {
        return Rapp;
    }
    else if((type == "House") || (type == "house"))
    {
        return House; 
    }
    else if((type == "Klassik") || (type == "klassik"))
    {
        return Klassik;
    }
    else
    {
        cout << "Dieses Genre ist in der Datenbank nicht  vorhanden." << endl;
    }
    
}
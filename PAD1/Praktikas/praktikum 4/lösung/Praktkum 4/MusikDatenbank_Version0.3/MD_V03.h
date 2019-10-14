#include <string>
#include <vector>


using namespace std;


enum Genre{Rock, Pop, Rapp, House, Klassik};


class Lied{
    private:
        string titel;
        string interpret;
        string erscheinungsjahr;
        string laenge;
        Genre genre;
        
    public:
        void setSong(string title, string artist, string year, string length, Genre type);
        string titleReturn();
        string getTitle();
        
        void setTitle();
        void setInterpret();
        void setYear();
        void setLen();
        void setGenre();
        
        void printTitle();
        void printDetails();
        
};





// Deklaration Funktionen
void menu(vector<Lied>& save);
void save(vector<Lied>& save, Lied& song); // Aufgabe 2
void newEntry(vector<Lied>& save); // 1. Neuer Eintrag
string printGenre(Genre genre);
//void showDetails();// 2. Details anzeigen
void listOfSongs(vector<Lied>& save);
bool isTitle(vector<Lied>& save, string title);
void printShowDetails(vector<Lied>& save);
void showAllEntries(vector<Lied>& save); // 6. Zeige alle Eintraege

void swap(Lied& a, Lied& b);
int select(vector<Lied>& save);
void del(vector<Lied>& save);

void edit(vector<Lied>& save);
Genre stringToGenre(string type);





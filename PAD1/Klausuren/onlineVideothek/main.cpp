/* 
 * File:   main.cpp
 * Author: fs
 *
 * Created on 2. Februar 2017, 13:14
 */

#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include "Benutzer.h"
#include "Video.h"
#include "onlineVideothek.h"

using namespace std;

int main(int argc, char** argv) {
    string m_benutzer;
    char auswahl= 'x' ;
    onlineVideothek v;
    v.createUser("test","test");
    v.addVideo(1,"test1",1);
      v.addVideo(2,"test2",10);
        v.addVideo(3,"test3",10);
          v.addVideo(4,"test4",10);
            v.addVideo(5,"test5",10);
              v.addVideo(6,"test6",10);
    

    while(auswahl!='0'){
        cout<<"***Online Videothek***"<<endl<<endl;
        cout<<"1: (V)ideo hinzufügen"<<endl;
        cout<<"2: (L)ogin"<<endl;
        cout<<"3: (F)avoriten anzeigen"<<endl;
        cout<<"4: (Z)u Favoriten hinzufügen"<<endl;
        cout<<"5: Videos (A)nzeigen"<<endl;
        cout<<"6: (N)ur neue Videos anzeigen"<<endl;
        cout<<"7: Fil(m) ansehen"<<endl;
        cout<<"0: E(X)it"<<endl<<endl;
        
        cout<<"Bitte wählen sie ein Menuepunkt aus"<<endl;
        cin>>auswahl;

        if(auswahl == '1' || auswahl=='v' || auswahl=='V'){
            int id;
            string titel;
            int max;
            cout<<"Bitte geben sie die Film ID an: ";
            cin>>id;
            cout<<endl<<"Bitte geben sie den Titel ein: ";
                    cin>>titel;
            cout<<endl<<"Bitte geben sie die maximale Anzahl an Zuschauern ein: ";
            cin>>max;
            v.addVideo(id,titel,max);
            
        }
         
        if(auswahl == '2' || auswahl=='l' || auswahl=='L'){
            int x;
            string name1, pw1,name2,pw2;
            cout<<"Wollen sie sich Einloggen oder Registrieren? \nwählen sie 1 für einloggen und 2 für registrieren"<<endl;
            cin>>x;
            if (x==1){
            cout<<"Bitte geben sie name und passwort ein. \n\nName: ";
            cin>>name1;
            cout<<"Passwort: ";
            cin>>pw1;
            if(v.login(name1,pw1)==true){
                cout<<"\n\n****Login erfolgreich!****"<<endl<<endl;
                m_benutzer=name1;
             
            }else cout<<"Keine Übereinstimmung gefunden..."<<endl;
            }
            if(x==2){ 
           cout<<"Bitte geben sie name und passwort ein. \n Name: ";
            cin>>name2;
             cout<<"Passwort: ";
            cin>>pw2;
            v.createUser(name2,pw2);
            v.login(name2,pw2);
            m_benutzer=name2;
            }
               
            
                    
        }
        if(auswahl == '3' || auswahl=='f' || auswahl=='F'){
            v.printFav(m_benutzer);
                   
              
                }
            
                
        
           
        
        
        if(auswahl == '4' || auswahl=='z' || auswahl=='Z'){
            int id;
            cout<<"geben sie die gewünschte ID an"<<endl;
            cin>>id;
            v.addToFavorites(m_benutzer, id);
        }
        if(auswahl == '5' || auswahl=='a' || auswahl=='A'){
            v.showAllVideos();
        }
        if(auswahl == '6' || auswahl=='n' || auswahl=='N'){
            v.showNew(m_benutzer);
        }
        if(auswahl == '7' || auswahl=='m' || auswahl=='M'){
            int ID;
            cout<<"Geben sie eine Film ID ein um ihn zu schauen: "<<endl;
            cin>>ID;
            v.watch(m_benutzer,ID);
        }

    }

    return 0;
}


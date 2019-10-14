/* 
 * File:   onlineVideothek.cpp
 * Author: fs
 * 
 * Created on 2. Februar 2017, 13:25
 */

#include "onlineVideothek.h"
#include "Benutzer.h"
#include "Video.h"


onlineVideothek::onlineVideothek() {
}

onlineVideothek::~onlineVideothek() {
}

int onlineVideothek::createUser(string name, string password){

 
     for (auto i=0;i<user.size();i++){
        if (name==user.at(i).GetName()){
            
            cout<<"Benutzer bereits vorhanden";
            return 0;
        }
 }
     Benutzer b(name, password);
     user.push_back(b);
}

int onlineVideothek::addVideo(int id, string titel, int maxView){
       
            for (auto i=0;i<videos.size();i++){
        if (id==videos.at(i).GetId()){
            
            cout<<"Video bereits vorhanden";
            return 0;
        }
            }         
        Video v(id,titel,maxView);
        videos.push_back(v);
}

bool onlineVideothek::login (string name, string password){
    for (auto i=0;user.size();i++){
        if(user.at(i).GetName()==name && user.at(i).GetPwd()==password)
            return true;
    }
    return false;
}

void onlineVideothek::showAllVideos() {
    for (auto i=0;i<videos.size();i++){
        cout<<"ID: "<<videos.at(i).GetId()<<endl<<"Titel: "<<videos.at(i).GetTitel()<<endl<<endl;
    }

}

bool onlineVideothek::exist(int id) {
 for(auto j=0;j<videos.size();j++)
                if(id==videos.at(j).GetId()){
                    return true;}
 return false;
}

bool onlineVideothek::exist(string name){
      for(auto i=0;i<user.size();i++){
        if(name==user.at(i).GetName()){
            return true;}
        return false;
      }
}

void onlineVideothek::addToFavorites(string benutzer, int id) {
    
//    if(exist(benutzer)==true){   benötigt man nicht, da der Benuter im Login geprüft wird..
    if(exist(id)==true){    
    
        for(auto i=0;i<user.size();i++){
      if(user.at(i).GetName()==benutzer){
          user.at(i).GetListe().push_back(id);
      }
        }                             
}else cout<<"id existiert nicht"<<endl;

//}else cout<<"benutzer existiert nicht"<<endl;
}

void onlineVideothek::watch(string benutzer, int id) {
    for (auto i=0;i<videos.size();i++){
       if(videos.at(i).GetId()==id){
           if(videos.at(i).GetMaxView()>videos.at(i).GetCurrentView()){
               for(auto j=0;j<user.size();j++){
                   if(user.at(j).GetName()==benutzer){
                       user.at(j).SetCurrentVideo(id);
                       videos.at(i).SetCurrentView();
                       cout<<"Der Film mit der ID: "<<id<<" wird angeschaut"<<endl;
                   }
               }
           }else cout<<"Maximale Anzahl an Zuschauern erreicht"<<endl;
               
       }
    }
}

vector<Benutzer> onlineVideothek::getUser() const {
    return user;
}

void onlineVideothek::showNew(string name) {
    int x=nameToIndex(name);
    for (auto j=0;j<user.at(x).GetListe().size();j++)
          for (auto k=0;k<videos.size();k++){
        if(videos.at(k).GetId()!=user.at(x).GetListe()[j])
        cout<<"ID: "<<videos.at(k).GetId()<<endl<<"Titel: "<<videos.at(k).GetTitel()<<endl<<endl;
    }
    }


    


int onlineVideothek::nameToIndex(string name) {
   
    for(auto i=0;i<user.size();i++){
        if(user.at(i).GetName()==name) {
            return i;
        }
}
}

void onlineVideothek::printFav(string name) {

 int x=nameToIndex(name);
    for (auto j=0;j<user.at(x).GetListe().size();j++)

    for (auto k=0;k<videos.size();k++){
        if(videos.at(k).GetId()==user.at(x).GetListe()[j]){
                cout<<"ID: "<<user.at(x).GetListe()[j]<<endl;
                cout<<"Titel:"<<videos.at(k).GetTitel()<<endl<<endl;
        }


    }
        
}
   // cout<<"Titel: "<<endl<<endl;
   
 

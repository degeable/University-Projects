/* 
 * File:   onlineVideothek.h
 * Author: fs
 *
 * Created on 2. Februar 2017, 13:25
 */

#ifndef ONLINEVIDEOTHEK_H
#define	ONLINEVIDEOTHEK_H
#include <string>
#include <vector>
#include "Benutzer.h"
#include "Video.h"
#include <iostream>
using namespace std;

class onlineVideothek {
public:
    onlineVideothek();
    virtual ~onlineVideothek();
    void printFav(string name);

   int createUser(string name, string password);
   int addVideo(int id, string titel, int maxView);
   bool login(string name, string password);
   void showAllVideos();
   void addToFavorites(string benutzer, int id);
   void watch(string benutzer, int id);
   vector<Benutzer> getUser() const;
   void showNew(string name);
   bool exist(int id);
   bool exist(string name);
   int nameToIndex(string name);
private:
    vector<Benutzer>user;
    vector<Video>videos;
    
};

#endif	/* ONLINEVIDEOTHEK_H */


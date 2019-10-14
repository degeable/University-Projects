/* 
 * File:   Benutzer.h
 * Author: fs
 *
 * Created on 2. Februar 2017, 13:19
 */

#ifndef BENUTZER_H
#define	BENUTZER_H
#include <string>
#include <vector>

using namespace std;

class Benutzer {
public:
    Benutzer(string Name, string Pwd);
//    void printFav();
    virtual ~Benutzer();
    string GetName() const;
    string GetPwd() const;
    vector<int>& GetListe() ;
    void SetCurrentVideo(int currentVideo);
    int GetCurrentVideo() const;
private:
    string name;
    string pwd;
    vector<int>liste;
    int currentVideo;
};

#endif	/* BENUTZER_H */


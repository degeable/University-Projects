/* 
 * File:   Video.h
 * Author: fs
 *
 * Created on 2. Februar 2017, 13:14
 */

#ifndef VIDEO_H
#define	VIDEO_H
#include <string>

using namespace std;

class Video {
public:
    Video(int ID, string Titel, int max);
    
    virtual ~Video();
    int GetId() const;
    string GetTitel() const;
    int GetMaxView() const;
    void SetCurrentView();
    int GetCurrentView() const;
private:

    int id;
    string titel;
    int maxView;
    int currentView;
};

#endif	/* VIDEO_H */


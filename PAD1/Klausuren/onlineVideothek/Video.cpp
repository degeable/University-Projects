/* 
 * File:   Video.cpp
 * Author: fs
 * 
 * Created on 2. Februar 2017, 13:14
 */

#include "Video.h"

Video::Video(int ID, string Titel, int max){
    id=ID;
    titel=Titel;
    maxView=max;
    currentView=0;
}



Video::~Video() {
}

int Video::GetId() const {
    return id;
}

string Video::GetTitel() const {
    return titel;
}

int Video::GetMaxView() const {
    return maxView;
}

void Video::SetCurrentView() {
    this->currentView +=1;
}

int Video::GetCurrentView() const {
    return currentView;
}


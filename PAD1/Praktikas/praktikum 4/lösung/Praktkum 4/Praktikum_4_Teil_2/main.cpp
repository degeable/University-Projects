/* 
 * File:   main.cpp
 * Author: fs
 *
 * Created on 15. November 2016, 14:47
 */

#include <cstdlib>
#include <iostream>
#include </home/fs/Schreibtisch/Praktika/PAD/Praktkum 4/Praktikum_4_Teil_2/PR4_Teil2.h>

using namespace std;


/*
 * 
 */
int main(int argc, char** argv) {
    int i = 2;
    int j = 4;
    
    int i2 = 4;
    int j2 = 8;
    
    int i3 = 20;
    int j3 = 10;
    
    float r = 2.5;
    float len = 12.0;
    float wi = 3.0;
    
    Dot_2D coord;
    coord.create(i, j);
    
    Dot_2D coord2;
    coord2.create(i2, j2);
    
    Dot_2D coord3;
    coord3.create(i3, j3);
    
    Kreis k;
    k.create(coord, r);
    
    Dreieck t;
    t.create(coord, coord2, coord3);
    
    Rechteck rec;
    rec.create(coord, len, wi);
    
    cout << "Kreisumfang: " << umfang(k) <<endl;
    cout << "Dreiecksumfang: " << umfang(t) << endl;
    cout << "Rechtecksumfang: " << umfang(rec) << endl <<endl; 
    
    cout << "Kreisflaeche: " << flaeche(k) <<endl;
    cout << "Dreiecksflaeche: " << flaeche(t) << endl;
    cout << "Rechtecksflaeche: " << flaeche(rec) << endl; 

    
    return 0;
}


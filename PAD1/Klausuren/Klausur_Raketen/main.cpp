/* 
 * File:   main.cpp
 * Author: fs
 *
 * Created on 10. Januar 2017, 12:30
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include "Triebwerke.h"
#include "Tank.h"
#include "Rakete.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Rakete r;

    Triebwerke tw0("LVT-30", 2000, 0.5, 2.5);
    Triebwerke tw1("LVT-45", 3500, 0.75, 4);
    Triebwerke tw2("LVT-80", 10000, 1.5, 10.5);



    Tank t0("Kleiner Treibstofftank", 1, "TREIBSTOFF", 20, 0, 1);
    Tank t1("Mittlerer Treibstofftank", 3, "TREIBSTOFF", 80, 0, 3);
    Tank t2("Großer Treibstofftank", 5, "TREIBSTOFF", 200, 0, 5);
    Tank t3("Kleiner Nutzlastcontainer", 1, "NUTZLAST", 10, 0, 1);
    Tank t4("Grosser Nutzlastcontainer", 5, "NUTZLAST", 100, 0, 5);


    int index = 0;
    char input;
    while (input != 'x') {
        cout << "1. Tankliste ausgeben\n";
        cout << "2. Triebwerksliste ausgeben\n";
        cout << "3. Rakete anzeigen\n";
        cout << "4. Tank hinzufügen\n";
        cout << "5. Triebwerk hinzufügen\n";
        cout << "x. Beenden\n";
        char input;
        cin>>input;
        if (input == '1') {
            cout << "t0:" << endl;
            t0.print(t0);
            cout << "t1:" << endl;
            t1.print(t1);
            cout << "t2:" << endl;
            t2.print(t2);
            cout << "t3:" << endl;
            t3.print(t3);
            cout << "t4:" << endl;
            t4.print(t4);
        }
        if (input == '2') {
            cout << "tw0:" << endl;
            tw0.print();
            cout << "tw1:" << endl;
            tw1.print();
            cout << "tw2:" << endl;
            tw2.print();
        }
        if (input == '3') {

            r.print();
        }
        if (input == '4') {
            cout << "Welchen tank?(t0-t4)\n";
            string tnk;
            int voll;
            cin>>tnk;
            cout << "Wie voll soll der Tank sein?(in %)\n";
            cin>>voll;
            if (tnk == "t0") {
                r.einfuegen(t0, index, voll);
            }
            if (tnk == "t1") {
                r.einfuegen(t1, index, voll);
            }
            if (tnk == "t2") {
                r.einfuegen(t2, index, voll);
            }
            if (tnk == "t3") {
                r.einfuegen(t3, index, voll);
            }
            if (tnk == "t4") {
                r.einfuegen(t4, index, voll);
            }

            index++;
        }
        if (input == '5') {
            cout << "welches Triebwerk?(tw0-2)\n";
            string trieb;
            cin>>trieb;
            if (trieb == "tw0")
                r.einfuegen(tw0);
            if (trieb == "tw1")
                r.einfuegen(tw1);
            if (trieb == "tw2")
                r.einfuegen(tw2);
        }
        if (input == 'x')
            break;

    }
    return 0;
}






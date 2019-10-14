/* 
 * File:   main.cpp
 * Author: fs
 *
 * Created on 19. Oktober 2016, 10:27
 */

#include <iostream>
#include <cmath>

using namespace std;


int main (){
    int a;
    cout << "geben sie eine Zahl ein: ";
    cin >>a;
    if (a>9,a<99){
    cout << a/10<< endl;
    cout<< a/1%10<<endl;
    }
    else if  (a>99,a<999){
         cout << a/(100)<< endl;
    cout<< a/10%10<<endl;
    cout<< a/1%10<<endl;
    }
    else if  (a>999,a<9999){
         cout << a/(1000)<< endl;
    cout<< a/100%10<<endl;
    cout<< a/10%10<<endl;
    cout<< a/1%10<<endl;
    }
    else if (a>9999,a<99999){
         cout << a/(10000)<< endl;
    cout<< a/1000%10<<endl;
    cout<< a/100%10<<endl;
    cout<< a/10%10<<endl;
    cout<< a/1%10<<endl;
    }
    else if (a>99999,a<999999){
            cout << a/(100000)<< endl;
    cout<< a/10000%10<<endl;
    cout<< a/1000%10<<endl;
    cout<< a/100%10<<endl;
    cout<< a/10%10<<endl;
    cout<< a/1%10<<endl;
    }
    }
    
    




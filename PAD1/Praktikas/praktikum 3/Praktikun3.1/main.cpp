/* 
 * File:   main.cpp
 * Author: fs
 *
 * Created on 31. Oktober 2016, 12:16
 */

#include <cstdlib>
#include <iostream>

using namespace std;

void histogramm(){
 int N;
    cout<<"Wie viele Zahlen wollen sie eingeben?"<<endl;
    cin>>N;
    int a[N];
    cout<<"Bitte geben sie nun ihre "<<N<<" Zahlen ein"<<endl;
    for (int i=0;i<N;i++){
        cin>>a[i];
    }
    for (int i=0;i<N;i++){
  
         while (a[i]>0){
             cout<<"*";
         a[i]--;        
         }
         cout<<endl;
     }

}

int main(){
    histogramm();
    return 0;
}


       




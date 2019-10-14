/* 
 * File:   main.cpp
 * Author: fs
 *
 * Created on 8. Oktober 2016, 14:55
 */

#include <iostream> 
#include <cmath>
#include <fstream>


using namespace std;
int main()
{
  double x,y,a,b;
  int summe;
  int differenz;
  
  cout <<"\n  x eingeben ";
  cin>>x;
  cout <<"\n  y eingeben ";
  cin>>y;
  
  a=x;
  a=x+y;
  
  b=x;
  b=x-y;
  
  cout <<"\n  summe von "<<x<<" und "<<y<<" = "<<a;
  cout <<"\n  differenz von "<<x<<" und "<<y<<" = "<<b;
  summe=a;
  differenz=b;
  
ofstream  fileout;
fileout.open("Ergebnisse.txt");
fileout  << "Die Summe von "<<x<<" und "<<y<<" ist"<<summe<<", die Differenz beträgt"<<differenz<<"";
fileout.close ();
  
}
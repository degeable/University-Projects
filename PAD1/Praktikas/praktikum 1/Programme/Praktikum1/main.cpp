// Wurzel berechnen
#include <iostream>  //Praeprozessordirektiven
#include <cmath>

using namespace std;
int main()
{
  const double genauigkeit=1.0e-3;
  double x,a;
  int schritte=0;
  //Eingabe
  cout <<"\n  a eingeben ";
  cin>>a;
  //Plausibilitaetskontrolle
  if ( a<=0 )// unzulaessige Eingabe
    cout <<"\n  a muss > 0 sein ";
  else
  {   //Verarbeitung
    x=a;
    while ( abs (x*x-a)>genauigkeit )//Wiederholungsbedingung
    { 
      x=x-(x*x-a)/(2*x);
      schritte++;
    } // Ende Wiederholung (Schleife)

    //Ergebnis
    cout <<"\n  Wurzel von "<<a<<" = "<<x;
    cout<<" nach "<<schritte<<" Schritten"<<endl;
  }
  return 0;
}


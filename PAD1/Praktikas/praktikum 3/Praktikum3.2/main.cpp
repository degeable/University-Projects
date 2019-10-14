#include <iostream>

using namespace std;

int main() 
{ 
  int a, i, b, temp;
  cout<<"Bitte geben sie 2 Zahlen ein ";
  cin>>a;
  cin>>b;
  if (b<a){
      temp=b;
      b=a;
      a=temp;
            
  }
  cout<<"Die Primzahlen zwischen "<<a<<" und "<<b<<" lauten: ";
  
  for (a=a;a <= b; a++) 
  { 
    for (i = 2; i <= a; i++) 
    { 
      if (a%i == 0) break; 
    } 
    if (i == a) cout<<i<<","; 
  } 
  return 0;
}

      
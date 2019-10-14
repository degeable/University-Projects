#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

void fill(vector<double>& v); //Befuellt einen vector mit Zufallswerten

int main()
{
  srand(time(0));
  vector<double> v1(1e5); //100.000 Elemente
  fill(v1);
  
  vector<double> v2 = v1; //v2 ist eine Kopie von v1
  
  time_t start = clock();
  sort(v1.begin(), v1.end());
  time_t stop = clock();
  cout << "sort aus stdlib: " << (stop - start) << endl;
  
  start = clock();
  //Aufruf Ihres Sortierverfahrens
  stop = clock();
  cout << "Mein eigener sort: " << (stop - start) << endl;
  
  return 0;
  
}

void fill(vector<double>& v)
{
  //Platz für eigene Implementierung
}

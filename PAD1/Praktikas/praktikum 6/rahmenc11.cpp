#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

void fill(vector<double>& v); //Befuellt einen vector mit Zufallswerten

int main()
{
  vector<double> v1(1e5); //100.000 Elemente
  fill(v1);
  
  vector<double> v2 = v1; //v2 ist eine Kopie von v1
  
  steady_clock::time_point start;
  steady_clock::time_point stop;
  
  start = steady_clock::now();
  sort(v1.begin(), v1.end());
  stop = steady_clock::now();
  cout << "sort aus stdlib: " << duration_cast<duration<double>>(stop-start).count() << endl;
  
  start = steady_clock::now();
  //Aufruf Ihres Sortierverfahrens
  stop = steady_clock::now();
  cout << "Mein eigener sort: " << duration_cast<duration<double>>(stop-start).count() << endl;
  
  return 0;
  
}

void fill(vector<double>& v)
{
  //Platz für eigene Implementierung
}

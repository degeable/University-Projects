#include <iostream>
 
using namespace std;
 
int main()
{
    int value;
    int min;
    int summe = 0;
    int counter = 0;
    
    cout<<"geben sie beliebige Zahlen ein"<<endl;
 
    while( value > 0 && cin >> value ) // , ??
    {
        if( counter == 0 )
            min = value;
 
        else if( min > value )
            min = value;
 
        summe += value;
        ++counter;
    }
    summe /= counter; // summe ist hier mittelwert
    cout << "Der Mittelwert beträgt " << summe << ", die kleinste eingegebene Zahl war die " << min << endl;
}
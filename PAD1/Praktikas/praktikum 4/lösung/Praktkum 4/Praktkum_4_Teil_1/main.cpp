/* 
 * File:   main.cpp
 * Author: fs
 *
 * Created on 15. November 2016, 13:23
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
bool isSorted(const vector<T>& vsorted){
    T min = vsorted[0];
    
    for(int i = 1; i<vsorted.size(); i++){
        if(vsorted[i]<min){
            return false;
        }
    }
    return true;
    
}

template<typename T>
T average(const vector<T>& vaverage){
    T sum = 0;
    
    for(int i = 0; i < vaverage.size(); i++){
        sum += vaverage[i];
    }
    T average = sum / vaverage.size();
    
    return average;
}

/*
 * 
 */
int main(int argc, char** argv) {

    vector<int> input_vec(0);
    int input;
    
    cout << "Geben Sie eine ganze Zahl ein." << endl;
    
    cin >> input;
    while(input > 0){
        input_vec.push_back(input);
        cin >> input;
    }
    
    cout << "\nSortiert?: " << isSorted<int>(input_vec) << endl << endl;
    cout << "Durschnitt: " << average<int>(input_vec);
    
    
    return 0;
}


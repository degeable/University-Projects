/* 
 * File:   main.cpp
 * Author: fs
 *
 * Created on 20. November 2016, 14:20
 */
#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;

template<typename T>

void getAverage(vector<T>&vec) {
    int i;

    double mitte = 0;

    int x = vec.size();

    for (i = 0; i < x; i++) {
        mitte = mitte + vec[i];
    }
    mitte = mitte / x;
    cout << mitte;

}

int main() {
    vector<int>vec(4);
    vec[0] = 1;
    vec[1] = 2;
    vec[2] = 3;
    vec[3] = 4;
    getAverage(vec);

}


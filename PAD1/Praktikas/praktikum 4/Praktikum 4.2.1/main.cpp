/* 
 * File:   main.cpp
 * Author: fs
 *
 * Created on 18. November 2016, 12:09
 */

#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

template<typename T>

bool isSorted(vector<T>&test) {
    int a;
    int size = test.size();
    for (int a = 0; a < (size - 1); a++) {
        if (test[a] <= test[a + 1])
            continue;
        else
            return false;

    }
    return true;
}

int main() {



    vector <int> v(4);
    const int s = 3;
    v[0] = 1;
    v[1] = 2;
    v[2] = 5;
    v[3] = 4;


    if (isSorted(v) == 1) {
        cout << "true";

    } else
        cout << "false";
}

#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include </home/fs/Schreibtisch/Praktika/PAD/Praktkum 4/Praktikum_4_Teil_3/PR4_Teil3.h>

using namespace std;

void randCube()
{
    int cube_1, cube_2, sum;
    vector<int> sumCube(12);
    
    for(int k = 0; k < sumCube.size(); k++)
    {
        sumCube[k] = 0;
    }
    
    for(int i = 1; i <= 1000000; i++)
    {
        cube_1 = (rand() % 6) + 1; 
        cube_2 = (rand() % 6) + 1;
        sum = cube_1 + cube_2;
        
        sumCube[sum - 1] += 1;
    }
    
    for(int j = 0; j < sumCube.size(); j++)
    {
        cout << j + 1 << " kam " << sumCube[j] << " mal raus." << endl; 
    }
    
}

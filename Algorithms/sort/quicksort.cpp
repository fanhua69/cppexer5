//
//  quicksort.cpp
//  testcpp2
//
//  Created by hua fan on 2023-08-23.
//

#include <stdio.h>
#include "headers.h"

namespace
{

int partition (vector<int> &data, int low, int hi)
{
    int f = low - 1;
    int t = hi + 1;
    int pivot = data[low];
    
    while(true)
    {
        do { f++; } while(data[f] < pivot);
        do { t--; } while(data[t] > pivot);
        if(f >= t) return t;
        swap(data[f], data[t]);
    }
}

void quicksort(vector<int> &data, int f, int t)
{
    if(f < t)
    {
        int j = partition(data,f,t);
        cout << j << ", ";
        print(data);
        quicksort(data, f, j);
        quicksort(data, j+1, t);
    }
}

}

void quicksortMain()
{

    vector<int> data ={5,5,5,5,4,3,3,4,4,2,3,1,1,2,2,3,2,1,11};
    quicksort(data, 0 , data.size()-1);

    print(data);
}

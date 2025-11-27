//
//  array1.cpp
//  testcpp3
//
//  Created by hua fan on 2024-02-01.
//

#include <stdio.h>
#include "headers.h"
#include <array>
#include <algorithm>

static void foo(int *p, int len)
{
    for(int i = 0; i< len; i++)
    {
        cout << p[i] << " ," ;
    }
    cout << endl;
}

void array_1_main()
{
    const int N = 5;
    std::array<int, N> arr = {1,2,3,4};
    for(auto i : arr)
    {
        cout << i << ", ";
    }
    cout << endl;

    std::sort(arr.begin(),arr.end(), [](int a, int b) { return a > b;});
    for(auto i : arr)
    {
        cout << i << endl;
    }

    foo(&arr[0], arr.size());
    foo(arr.data(), arr.size());



}

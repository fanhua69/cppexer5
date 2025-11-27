//
//  random1.cpp
//  testcpp3
//
//  Created by hua fan on 2025-10-01.
//


#include "headers_2.h"
#include <iostream>
#include <random>

using namespace std;

void random1_main()
{
    std::random_device rd;
    cout << rd() << endl;
    cout << rd() << endl;
    cout << rd() << endl;
    
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> dist(1,10);
    for(int i = 0; i < 5; ++i)
    {
        cout << dist(rd) << endl;
    }
}

//
//  spaceship.cpp
//  testcpp3
//
//  Created by hua fan on 2025-09-23.
//


#include "headers_2.h"
#include <iostream>
using namespace std;

void spaceship_main()
{
    float a = 1;
    float b = 2;
    std::partial_ordering c = a <=> b;
    int *p = reinterpret_cast<int*>(&c);
    if (c < 0)
        cout << "less:" << endl;
    cout << *p << endl;

}

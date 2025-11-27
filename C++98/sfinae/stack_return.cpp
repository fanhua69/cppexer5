//
//  stack_return.cpp
//  testcpp3
//
//  Created by hua fan on 2025-10-30.
//


#include "headers_2.h"
#include <iostream>
using namespace std;

bool isPowerOf2(unsigned int N)
{
    return ((N & N -1) == 0);
}

std::vector<unsigned int > splitN(unsigned int N)
{
    vector<unsigned int> r;
    unsigned int d = 1;
    while(N)
    {
        if(N & 1)
            r.push_back(d);
        N >>= 1;
        d *= 2;
    }
    return r;
}

void stack_return_main()
{
    auto r = splitN(19);
    for(auto n: r)
        cout << n << endl;
    
    cout << "Power of 2:" << isPowerOf2(1) << endl;
}


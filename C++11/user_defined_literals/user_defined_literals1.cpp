//
//  user_defined_literals1.cpp
//  testcpp3
//
//  Created by hua fan on 2025-09-23.
//


#include "headers_2.h"
#include <iostream>
using namespace std;

int operator ""_km(unsigned long long n)
{
    return n * 1000;
}

int operator ""_ton(long double d)
{
    return d * 1000;
}

void user_defined_literals1_main()
{
    int n = 123_km;
    cout << n << endl;
    
    int m = 1324.123_ton;
    cout << m << endl;
    
   
    
}

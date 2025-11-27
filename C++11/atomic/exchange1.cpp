//
//  exchange1.cpp
//  testcpp3
//
//  Created by hua fan on 2025-10-27.
//


#include "headers_2.h"
#include <iostream>
using namespace std;

atomic<bool> lk;

void mylock()
{
    while(lk.exchange(true))
    {}
}

void exchange1_main()
{
    
}

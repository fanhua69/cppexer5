//
//  apply1.cpp
//  testcpp3
//
//  Created by hua fan on 2025-09-13.
//


#include "headers_2.h"
#include <iostream>
using namespace std;

void apply1_main()
{
    std::tuple<int,int,int> t = { 1,2,3};
    
    auto l = [](int a, int b, int c)->int
    {
        return a + b + c;
    };
    
    cout << std::apply(l, t) << endl;
    
}

//
//  span1.cpp
//  testcpp3
//
//  Created by hua fan on 2025-11-11.
//


#include "headers_2.h"
#include <iostream>
#include <span>
#include <numeric>

using namespace std;

void modify(std::span<int> &s)
{
    cout << s.size() << endl;
    cout << s.extent << endl;
    print(s.subspan(3,5));
    
}

decltype(auto) aaaaddd(int x)
{
    int y = x;
    return (x);
}

void span1_main()
{
    std::vector<int> v(20,1) ;
    std::iota(v.begin(), v.end(), 1);
    print(v);
    
    std::span <int> s = std::span(v);
    print(s);
    s[1] = 10101;
    print(s);
    
    modify(s);
    
    auto d = aaaaddd(10);
    cout << typeid(d).name() << endl;
    
    
    int a = 0b1010'1011;
    cout <<  a << endl;
}

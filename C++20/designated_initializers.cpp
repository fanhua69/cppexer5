//
//  designated_initializers.cpp
//  testcpp3
//
//  Created by hua fan on 2025-10-26.
//


#include "headers_2.h"
#include <iostream>
#include <iomanip>
#include <source_location>

using namespace std;

namespace {
struct S
{
    int i;
    int j;
    float f;
    std::partial_ordering operator <=> (const S& o) const
    {
        if(auto cmp = i <=> o.i; cmp !=0)
            return cmp;
        else if(auto cmp = j <=> o.j; cmp != 0 )
            return cmp;
        else if(auto cmp = f <=> o.f; cmp != 0)
            return cmp;
        return std::partial_ordering::equivalent;
    }
};

}

void designated_initializers_main()
{
//    S s{.i = 2, .j = 3, .f = 123.32f};
//    S s2{.i = 2, .j = 3, .f = 123.32f};
//    
//    auto cmp = s <=> s2;
//    if(cmp < 0)
//        cout << "<"<< endl;
//    else if (cmp == 0 )
//        cout << "e" << endl;
//    else
//        cout << ">" << endl;
//    
//    string ss = std::format("sadfds {}: {} {}", s.i, s.j, s.f);
//    cout << ss << endl;
//    
//    cout << std::source_location::current().column() << endl;
//    
//    int a = 123;
//    cout << showbase << oct << a << endl;
//    
//    std::bitset<8> b = a;
//    std::bitset<8> b3(string("0101"), 2, 2);
//    cout << b3 << endl;
//    b3.set();
//    cout << b3 << endl;
//    b3.reset();
//    cout << b3 << endl;
//    b3.set(3);
//    cout << b3 << endl;
//    b3.flip();
//    cout << b3 << endl;
//    cout << b3.test(3) << endl;
//    cout << b3.count() << endl;
//    cout << b3.to_string() << endl;
//    
//    cout <<( b3 & b )<< endl;
//    cout << (~b) << endl;
//    cout << (b << 2) << endl;
//    
//    cout << std::format("{:b}", a) << endl;
//    cout << "binary:" << endl;
    
    int n = 1;
    bool started = false;
    for(int i = sizeof(n) * 8 -1; i >=0; --i)
    {
        if(n & (1u << i))
            started = true;
        if(started)
            cout << ((n>>i)&1);
    }
    cout << endl;
    
    cout << sizeof(double) << endl;
    cout << format("{:b}", 1 << 31) << endl;
    cout << format("{:b}", 1u << 31) << endl;
    cout << format("ee: {:b}", 1u << 32) << endl;

   
    
}

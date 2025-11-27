//
//  perfect_forwarding2.cpp
//  testcpp3
//
//  Created by hua fan on 2025-09-11.
//

#include "headers_2.h"
#include <iostream>
using namespace std;

namespace
{
void func(int &v)
{
    cout << "In left value :" << v << endl;
}

void func(int && v)
{
    cout << "In right value:" << v << endl;
}

template <typename T>
void wrapper(T&& v)
{
    cout << "Before calling:" << endl;
    func(std::forward<T>(v));
    cout << "end calling " << endl;
}

}


void perfect_forwarding2_main()
{
    wrapper(10);
    int a = 20;
    wrapper(a);
}

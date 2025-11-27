//
//  declvalue.cpp
//  testcpp3
//
//  Created by hua fan on 2025-11-22.
//


#include "headers_2.h"
#include <iostream>
using namespace std;

namespace
{
struct X {
    X(){};
    X(const X&) = delete;
    X(X&& ) = delete;
    ~X() { cout << "X is destructed" << endl;}
    int foo() const &&
    {
        return 42;
    }
};
}

void declvalue_main()
{
    X x;
    cout << typeid(decltype(declval<X>().foo())).name() << endl;
}

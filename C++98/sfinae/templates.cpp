//
//  templates.cpp
//  testcpp3
//
//  Created by hua fan on 2025-10-23.
//


#include "headers_2.h"
#include <iostream>
using namespace std;

namespace
{

struct A
{
    static int value;
};
int A::value = 0;

struct B{};

template <typename T>
int foo(decltype(T::value)*)
{
    cout << "has value" << endl;
    return 0;
}

template <typename T>
int foo(...)
{
    cout << "no value"<< endl;
    return 1;
}
}


void templates3_main()
{
    cout << foo<A>(nullptr) << endl;
    cout << foo<B>(nullptr) << endl;
}

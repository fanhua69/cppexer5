//
//  trait1.cpp
//  testcpp3
//
//  Created by hua fan on 2025-10-21.
//


#include "headers_2.h"
#include <iostream>
using namespace std;

template <typename T>
typename enable_if<is_integral_v<T>, void>::type
foo (T x)
{
    cout << "is integral :" <<  x<< endl;
}

template <typename T>
typename enable_if<is_floating_point<T>::value,void>::type
foo (T x)
{
    cout << " is float:" << x << endl;
}

void trait1_main()
{
    foo(1);
    foo(1.23);
}

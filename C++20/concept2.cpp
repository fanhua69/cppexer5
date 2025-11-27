//
//  concept2.cpp
//  testcpp3
//
//  Created by hua fan on 2025-10-22.
//


#include "headers_2.h"
#include <iostream>
using namespace std;

template<typename T>
concept rr = std::is_integral_v<T> || std::is_floating_point_v<T>;

template <typename T>
concept printable = requires(T a)
{
    cout << a << endl;
};

template <rr T>
T make_twice(T x)
{
    return x + x;
}

template <typename T>
concept printable2  = std::is_integral<T>::value || std::is_floating_point<T>::value;

template <typename T>
concept printable3 = requires(T a)
{
    a = a + 1;
};

template <printable3 T>
void pprint(T a)
{
    cout << a << endl;
}



void concept2_main()
{
    pprint(12);
}

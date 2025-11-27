//
//  sfinae2.cpp
//  testcpp3
//
//  Created by hua fan on 2025-10-23.
//


#include "headers_2.h"
#include <iostream>
#include <type_traits>

using namespace std;

namespace
{
template<typename T>
auto foo(T t) ->enable_if_t<!is_integral_v<T>, void>
{
    cout << "is not integral" << endl;
    return;
}

template <typename T>
auto foo(T t) -> enable_if_t<is_integral_v<T>, void>
{
    cout << "int " << endl;
    return ;
}

}
void sfinae2_main()
{
    foo(1);
    foo(1.3);    
}

//
//  concepts11.cpp
//  testcpp3
//
//  Created by hua fan on 2025-10-24.
//

#include <algorithm>
#include <numeric>
#include <type_traits>


namespace
{


template <typename T>
requires std::is_integral_v<T> or std::is_floating_point_v<T>
void foo(T t)
{
}

template <typename T>
concept sortable = requires (T t)
{
    std::sort(t.begin(), t.end());
};

template <sortable T>
void foo2(T t)
{
    std::sort(t.begin(), t.end());
}


}

#include "headers_2.h"
#include <iostream>
using namespace std;

void concepts11_main()
{
}

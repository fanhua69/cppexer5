//
//  traits2.cpp
//  testcpp3
//
//  Created by hua fan on 2025-09-09.
//

#include "headers_2.h"
#include <iostream>
using namespace std;
    
namespace
{

template <typename T>
void printTypeInfo() {
    if constexpr(std::is_integral_v<T>)
        cout << "Integral type" << endl;
    else if constexpr(std::is_floating_point_v<T>)
        cout << "Floating point " << endl;
    else
        cout << "other type" << endl;
}

}

void traits2_main()
{
    printTypeInfo<int>();
    printTypeInfo<double>();
    printTypeInfo<float>();
    printTypeInfo<string>();
}

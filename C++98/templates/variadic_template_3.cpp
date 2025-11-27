//
//  variadic_template_3.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-10.
//

#include <stdio.h>
#include "headers.h"

// Fold Expression c++17
template <typename  ...Args>
auto Output2(int a, Args... args)
{
    return (args + ... + a);
}

void variadic_template_3_main()
{
    cout << Output2(1,2,3,4) << endl;
}

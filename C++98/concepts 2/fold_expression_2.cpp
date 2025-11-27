//
//  fold_expression_2.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-09.
//

#include <stdio.h>
#include "headers.h"

template <typename... Args>
auto sum(Args... args)
{
    return (args + ...);
}

void fold_expression_2_main()
{
    cout << sum(1,2,3)<< endl;
}

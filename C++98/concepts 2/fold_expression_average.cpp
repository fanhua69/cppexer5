//
//  fold_expression_average.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-29.
//

#include <stdio.h>
#include "headers.h"
#include <iomanip>

template <typename R, typename ...Args>
R average(Args... args)
{
    R N = sizeof...(args);
    cout << "size: " << N << endl;
    cout << typeid(N).name() <<endl;
    return (args + ...) / N;
}


void fold_expression3_main()
{
    cout << std::defaultfloat << std::setprecision(3) << average<double>(1,2,3,4,5,6,7.7) << endl;
}

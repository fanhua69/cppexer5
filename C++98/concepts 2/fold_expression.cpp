//
//  fold_expression.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-09.
//

#include <stdio.h>
#include "headers.h"


template <typename First>
First sum1(First && value)
{
    return value;
}

template <typename First, typename Second, typename... Rest>
First sum1(First &&first, Second && second, Rest&&... rest)
{
    return sum1(first + second, forward<Rest> (rest) ...);
}


// C++17, fold expression:
template <typename First, typename... Rest>
First sum2(First&& first, Rest&&... rest)
{
    return (first + ... + rest);
}

void fold_expression_main()
{
    cout << sum1(1) << sum1(1,2) << sum1(1,2,3) << endl;
    cout << sum2(1) << sum2(1,2) << sum2(1,2,3) << endl;

}

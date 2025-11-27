//
//  three-way-comparison.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-28.
//

#include <stdio.h>
#include "headers.h"

void three_way_comparison_operator_main()  // c++20
{
    int a = 1;
    int b = 2;
    std::strong_ordering i = a <=> b;

    float c = 1;
    float d = 2;
    std::partial_ordering j = c <=> d;


    cout << typeid(i).name() << endl;

    if(j < 0)
        cout << " c < d " << endl;

}

//
//  range3.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-20.
//

#include <stdio.h>
#include <ranges>

#include "headers.h"

void range3_main()
{
    std::vector vec{1,12,32,54,10086,-1314};
    auto res = vec | std::views::filter([](int n) { return n % 2 == 0;})
                    | std::views::transform([](int n) { return n* 2;});

    cout << typeid(res).name() << endl;

    for (auto v : res)
    {
        cout << v << endl;
    }


    auto res2 = vec;
    cout << typeid(res2).name() << endl;
}



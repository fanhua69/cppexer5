//
//  datatypes.cpp
//  testcpp2
//
//  Created by hua fan on 2023-11-08.
//

#include <stdio.h>
#include "headers.h"
#include <algorithm>


void dataTypesMain()
{
    long long a;
    cout << sizeof(a) << endl;

    vector<int> v {1,2,3,4,5,6,7};
    for(auto i : v)
    {
        cout << i << endl;
    }

    auto isPositive = [](int i) {return i> 0;};
    cout << typeid(isPositive).name() << endl;

    cout << all_of(v.begin(), v.end(), [](int i) {return i> 0;}) <<endl;

    struct DivisibleBy
    {
        const int d;
        DivisibleBy(int n) : d(n)
        {
        }

        bool operator()(int n)const
        {
            return n % d == 0;
        }
    };

    if (std::any_of(v.begin(), v.end(), DivisibleBy(5)))
        std::cout << "At least one is divisible by 7\n";


    std::tuple<int,int,int> p = {1,2,3};
    cout << get<2>(p) << endl;
}

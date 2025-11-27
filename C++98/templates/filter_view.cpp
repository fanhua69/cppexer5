//
//  filter_view.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-17.
//

#include <stdio.h>
#include <iostream>
#include <ranges>
#include "headers.h"
#include <numeric>


void filter_view_main()
{
    auto even = [](int i) { return 0 == i % 2; };
    auto square = [](int i) { return i * i; };
 
    for (int i : std::views::iota(0, 6)
               | std::views::filter(even)
               | std::views::transform(square))
        std::cout << i << ' ';


    auto v = std::views::iota(1,11);
    cout << typeid(v).name() << endl;

    for (auto i : std::views::iota(1,10))
    {
        cout << i << endl;
        cout << typeid(i).name() << endl;
    }

    std::cout << '\n';

    std::vector<int> res(pow(10,2)-1,0);
    std::iota(res.begin(),res.end(),1);
    for(auto i : res )
        cout << i << ", ";
    cout << endl;


}



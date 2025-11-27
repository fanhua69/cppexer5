//
//  ranges2.cpp
//  testcpp3
//
//  Created by hua fan on 2025-06-24.
//

#include "headers_2.h"
#include <iostream>
#include <ranges>
#include <numeric>

using namespace std;

bool isOdd(int x)
{
    return x % 2;
}

void ranges2_main()
{
    //for(int prime : take(filter(itoa_view(1), isOdd), 1000))
    //    cout << prime << ", " ;
    
    
    auto odds = std::views::iota(1) |
    std::views::filter(isOdd) |
    std::views::take(1000);
    

    
    for(auto i : std::views::iota(1,12))
    {
        cout << i << ", " ;
        if (i > 100)
            break;
    }
    
    auto o = std::views::iota(1) | std::views::filter([](int i){return i % 3 == 0;}) | std::views::take(10);
    cout << typeid(o).name() << endl;
    
    
    vector<int> v(100, 0);
    std::iota(v.begin(), v.end(), 111);
    for(auto i : v)
        cout << i << endl;
    
    
    std::map<int, string> m;
    m.emplace(1,"234");
    m.insert({2,"sddss"});
    cout << m[1] << endl;
    cout << m[2] << endl;
}
    

//
//  ranges1.cpp
//  testcpp3
//
//  Created by hua fan on 2025-06-13.
//

#include "headers_2.h"
#include <iostream>
#include <ranges>
#include <algorithm>

using namespace std;
using namespace std::ranges;
    
void ranges1_main()
{
    std::vector<int> v{1,5, 6, 2,3,4,5};
    std::ranges::sort(v);
    print(v);
    
    auto it = ranges::find(v, 1);
    cout << *it << endl;
    
    auto it2 = std::find(v.begin(), v.end(), 5);
    cout << *it2 << endl;
    
    auto v2 = std::views::filter(v,[](auto i){return i < 4;});
    for(auto i : v2)
    {
        cout << i << ", " << endl;
    }
    
    auto v3 = std::views::transform(v, [](auto i ){return i*2;});
    for (auto i : v3)
        cout << i << "...";
    
}

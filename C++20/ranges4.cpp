//
//  ranges4.cpp
//  testcpp3
//
//  Created by hua fan on 2025-10-22.
//


#include "headers_2.h"
#include <iostream>
#include <ranges>
#include <algorithm>


using namespace std;

void ranges4_main()
{
    std::list<int> l {0,1,2,3,4,5,6,7,8,9};
    std::list<int> v{6,7,8,9};
    
    auto it = v.begin();
    auto it3 = std::next(it, 1);
    std::advance(it3, 1);
    ranges::generate(v.begin(), it3, [](){return 1;});

    cout << std::ranges::distance(l) << endl;
    
    for(auto x : v)
        cout << x << endl;
    
}

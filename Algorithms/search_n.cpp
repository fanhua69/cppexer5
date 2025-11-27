//
//  search_n.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-16.
//

#include <stdio.h>
#include "headers.h"
#include <algorithm>

void search_n_main()
{
    vector<int> v {7,8,5,5,5,6};

    auto it = std::search_n(v.begin(), v.end(), 5, 6, [=](const auto &a, const auto &b)
                                                         {
                                                            cout <<  a << ", " << b << endl;
                                                             return a <= b;
                                                         });

    cout << *it << endl;
    cout << it - v.begin()  << endl;
}

//
//  set_union.cpp
//  testcpp2
//
//  Created by hua fan on 2023-08-13.
//

#include <stdio.h>
#include "headers.h"
#include <algorithm>
#include <iterator>


void set_union_test()
{
    vector<int> a {3,2,5};
    vector<int> b {9,7,8};

    vector<int> c;
    c.resize(a.size() + b.size());
    std::set_union(a.begin(),a.end(), b.begin(), b.end(), c.begin());


    vector<int> d;
    std::copy(a.begin(), a.end(), std::back_inserter(d));
    std::copy(b.begin(), b.end(), std::back_inserter(d));

    print(d);


    vector<int> e;
    e.resize(a.size() + b.size());
    std::copy(a.begin(), a.end(), e.begin());
    std::copy(b.begin(), b.end(), e.begin());

    print(e);

    vector<int> f;
    f.insert(f.begin(), a.begin(), a.end());
    f.insert(f.begin(), b.begin(), b.end());

    print(f);

}

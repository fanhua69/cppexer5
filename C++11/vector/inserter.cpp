//
//  inserter.cpp
//  testcpp3
//
//  Created by hua fan on 2025-07-21.
//

#include "headers_2.h"
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;
    
void inserter_main()
{
    vector<int> v {1,2,3,4,5};
    vector<int> v2 {1,2,3, 7,8,9};

    std::vector<int> vv;
    std::insert_iterator iti = std::inserter(vv, vv.end());
    std::copy(v2.begin(),v2.end(), iti);
    for(auto i : vv)
    {
        cout << i << endl;
    }
    
    
    vector<int> v3;
    std::back_insert_iterator<vector<int>> it3 = std::back_inserter(v3);
    std::merge(v.begin(), v.end(), v2.begin(), v2.end(), it3);
    
    for(auto i : v3)
        cout << i << ", " << endl;
    
    vector<int> v4;
    std::back_insert_iterator it4 = std::back_inserter(v4);
    std::set_union(v.begin(), v.end(), v2.begin(), v2.end(), it4);
    for(auto i : v4)
        cout << " union: " << i << endl;
    
    vector<int> v5;
    std::back_insert_iterator <vector<int>> it5 = std::back_inserter(v5);
    std::set_intersection (v.begin(), v.end(), v2.begin(), v2.end(), it5);
    for(auto i : v5)
        cout << " intersection : " << i << endl;
    
    vector<int> v6;
    std::back_insert_iterator<vector<int>> it6 = std::back_inserter(v6);
    std::set_difference(v.begin(),v.end(), v2.begin(), v2.end(), it6);
    for(auto i : v6)
        cout << "difference:" << i << endl;
    
    vector<int> v7;
    std::back_insert_iterator<vector<int>> it7 = std::back_inserter(v7);
    std::set_symmetric_difference(v.begin(), v.end(), v2.begin(), v2.end(), it7);
    for(auto i : v7)
        cout << " symmetric difference: " << i << endl;
    
    
    vector<int> v8;
    std::transform(v.begin(), v.end(), std::back_inserter(v8),[](int x) { return x * 2;});
    for(auto i : v8)
        cout << "transfom:" << i << endl;
    
    
    vector<int> v9(v.size());
    std::transform(v.begin(), v.end(), v8.begin(), v9.begin(), [](int x, int y ) { return x * y;});
    print(v9);
    
    vector<int> v10 (v.size());
    
    
    vector<int> af {1,2,3,4,5,6,6,6,7,8,9};
    auto p = std::adjacent_find(af.begin(), af.end());
    if(p != af.end())
        cout << *p << ", " << *(p+1) << endl;
    
    
    
    
}

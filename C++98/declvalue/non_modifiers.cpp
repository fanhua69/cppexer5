//
//  non_modifiers.cpp
//  testcpp3
//
//  Created by hua fan on 2025-07-22.
//

#include "headers_2.h"
#include <iostream>
#include <algorithm>

using namespace std;
    
void non_modifiers_main()
{
    vector<int> v{1,2,3,3,4,5,6,7,8,9,1,2,2,2,3,3};
    int n = std::count_if(v.begin(), v.end(), [](int s ){return s > 2;});
    cout << n << endl;
    
    vector<int> v2{1,2,3,3,4,5,6,7,8,9,1,2,2,2,3};
    bool b = std::equal(v.begin(), v.end(), v2.begin(), v2.end());
    print(b);
    
    auto it = std::find(v.begin(), v.end(), 3);
    cout << *it << endl;
    
    auto it2 = std::find_end(v.begin(), v.end(), v2.begin() + 7, v2.begin() + 9);
    cout << it2 - v.begin() << endl;
    
    auto it3 = std::find_first_of(v.begin(), v.end(), v2.begin() + 2, v2.begin() + 3);
    cout << *it3 << ", " << it3 - v.begin() << endl;
    
    for_each(v.begin(), v.end(), [](int &x) {x*=2;});
    print(v);
    
    auto it5 = std::mismatch(v.begin(), v.end(), v2.begin(), v2.end());
    if(it5.first  != v.end() && it5.second != v2.end())
        cout << *it5.first << endl;
    
    if(none_of(v.begin(),v.end(), [](int x){return x > 100;}))
    {
        cout << "all below 100" << endl;
    }
    
    print(v);
    print(v2);
    auto it6 = std::search(v.begin(), v.end(), v2.begin(), v2.begin() + 2);
    if(it6!=v.end())
        cout << *it6 << endl;
    else
        cout << "not found " << endl;
    
    bool b2 = std::lexicographical_compare(v.begin(), v.end(), v2.begin(), v2.begin() + 2);
    print(b2);
    
    //bool b3 = std::lexicographical_compare3way(v.begin(), v.end(), v2.begin(), v2.end());
    //print(b3);
    
    
    
}

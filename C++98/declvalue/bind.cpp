//
//  bind.cpp
//  testcpp3
//
//  Created by hua fan on 2024-11-23.
//

#include <vector>

#include <iostream>
#include <set>
#include <functional>
#include "print.h"
#include <utility>
#include <algorithm>
#include <random>
#include <map>
#include <numeric>

using namespace std;


void bindMain()
{
    string s1 = "abcccde";
    string s2 = "abcde";
    int n = count(s1.begin(), s1.end(), 'c');
    print(n);
    n = count_if(s1.begin(), s1.end(), [](char c) { return c < 'e';});
    print(n);

    string::iterator it = std::search_n(s1.begin(), s1.end(), 2, 'c');

    cout << *it<< endl;
    s1.erase(it, it+4);
    print(s1);
    s1.insert(it, 3, 'x');
    print(s1);

    vector<int> v;
    v.insert(v.begin(), 2, 1234);
    print(v);

    v.erase(v.begin(), v.begin()+1);
    print(v);

    s1.replace(1, 2 , 3, 'c');
    print(s1);



}

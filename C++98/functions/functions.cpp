//
//  functions.cpp
//  testcpp2
//
//  Created by hua fan on 2023-12-20.
//

#include <stdio.h>
#include <iostream>
#include <functional>
#include "headers.h"
#include <queue>

template <typename T>
using Vector = std::vector<T>;

using FV = std::vector<string>;


auto l = [](const int &a, const int &b)
{
    return a < b;
};


template <typename T>
using PQ = std::priority_queue<T, vector<T>, decltype(l)>;

auto lllp1()
{
    return "dsfdf";
}

decltype(auto) lllll()
{
    return lllp1();
}


void functionalMain()
{
    char *s= "abc";
    char *s2= "abc";
    cout << (void*)s << ", " << (void*)s2 << endl;
    char *p = s;
   

    string i = move (s2);
    cout << i << ", ffff " << s2  << endl;

}


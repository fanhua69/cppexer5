//
//  template_specialization.cpp
//  testcpp3
//
//  Created by hua fan on 2025-10-21.
//


#include "headers_2.h"
#include <iostream>
using namespace std;

template <typename T>
struct Printer
{
    static void print(T x)
    {
        cout << "Generic" << x << endl;
    }
};

template <>
struct Printer<int>
{
    static void print(int x)
    {
        cout << " int " << x <<  endl;
    }
};

template <typename T>
auto fooo(T t) -> decltype(t + 1, void())
{
    cout << t + 1 << endl;
}

template <typename T>
auto fooo(T t) ->decltype(t.size(), std::declval<T>())
{
    cout << "sizable" << endl;
    return t;
}


void template_specialization_main()
{
    Printer<int>::print(123.123);
    Printer<float>::print(2134.3214);
    int n = 0;
    fooo(n);
    
//    string s = "aaa";
//    fooo(s);
    vector<int> v;
    fooo(v);

    
}

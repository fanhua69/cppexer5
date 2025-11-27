//
//  for_each1.cpp
//  testcpp3
//
//  Created by hua fan on 2025-10-23.
//


#include "headers_2.h"
#include <iostream>
#include <algorithm>
#include <execution>
#include <numeric>
#include <variant>
#include <any>


using namespace std;

namespace
{

struct Sum
{
    int total = 0;
    void operator()(int x) { total += x;}
};

template <typename ...Args>
void print(Args ...args)
{
    (cout << ... << args);
}

template <typename T, typename ...Args>
void print2(T t, Args ...args)
{
    cout << sizeof...(args) << endl;
    cout << t ;
    ((cout << ", " << args),...);
    cout << endl;
    
    (cout << ... << args);
}

void foo( int & n)
{
    cout << "left reference :" << n << endl;
}

void foo(int &&n)
{
    cout << "right value reference:" << n << endl;
}

template <typename T>
void transfer(T && t)
{
    foo(static_cast<T&&>(t));
    //foo(std::forward<T> (t));
}

template <typename T>
auto addable(T a, T b) -> decltype(a+b)
{
    cout << a + b << endl;
    return a + b;
}

template <typename T>
void addable(T a, T b)
{
    cout << "not addable    " << endl;
}

}

void for_each1_main()
{
    addable("aa", "aa");
}

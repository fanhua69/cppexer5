//
//  ranges11.cpp
//  testcpp3
//
//  Created by hua fan on 2025-10-24.
//


#include "headers_2.h"
#include <iostream>
#include <ranges>
#include <algorithm>

using namespace std;


template <typename T>
concept cc = std::integral<T> || std::floating_point<T>;

template <typename T>
requires cc<T>
void foo(T t)
{
}

template <cc T>
void foo(T t)
{
}

template <typename T>
requires std::integral<T> || std::floating_point<T>
void foo(T t)
{}

template<typename T>
requires std::is_integral<T>::value || std::is_floating_point<T>::value
void foo()
{
}



void ranges11_main()
{
    vector<int> v {1,2,3,4,5,6,8,9,10};
    auto r = v | std::views::filter([](int x){return x%2 == 0;})
               | std::views::drop(1)
               | std::views::take(3);
    
    std::ranges::sort(v);
    for (auto x : r)
        cout << x << endl;
    
    auto vv = std::views::all(v);
    for(auto x : vv)
        cout <<  x << endl;
    
    auto v3 = std::ranges::subrange(v.begin(), v.begin() + 5);

    auto v4 = std::ranges::ref_view(v3);
    for(auto &x : v4)
    {
        x *= 2;
        cout << x << endl;
    }
    for(auto x : v3)
        cout << x << endl;
    
    cout << boolalpha << std::is_integral_v<int> << endl;
    cout << boolalpha << std::integral<int> << endl;
    cout << boolalpha << std::floating_point<float> << endl;
    cout << boolalpha << std::floating_point<decltype(1.1)> << endl;
    
    auto v1 = v | std::views::transform([](auto x){return x * 2;});
    for(auto x : v1)
        cout << x << endl;
    
    auto t = std::make_tuple(1,3,4);
    std::apply([](auto x, auto y, auto z){ x * 2;}, t);
    for(auto x : v)
        cout << x << endl;
    
    auto result = std::for_each(v.begin(), v.end(), [](int &x){ x *= 2;});
    cout << typeid(result).name() << endl;
    for(auto x : v)
        cout << x << endl;
    
    
}

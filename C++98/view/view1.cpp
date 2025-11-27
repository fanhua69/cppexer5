//
//  view1.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-25.
//

#include <stdio.h>
#include <vector>
#include "headers.h"
#include <ranges>
#include <algorithm>
#include <tuple>
#include <string>
#include <iomanip>

#include <ranges>
#include <iostream>


// std::views c++20

template <typename T>
void printv( T& t)
{
    for ( auto i : t)
    {
        cout << i << ", ";
    }
    cout << endl;
}

void view1_main()
{
    vector<int> v {1,2,3,4,5,6,7,8};
    auto v1 = v| std::views::filter([](int a) { return a % 2 == 0;});
    printv(v1);

    auto v2 =  std::views::all(v);
    printv(v2);

    auto v3 = v | std::views::drop(2);
    printv(v3);

    if (std::find_if(v.cbegin(), v.cend(), [](auto i) { return i == 5;}) != v.end())
    {
        cout << " in " << endl;
    }

    auto n = std::count(v.cbegin(), v.cend(), 3);
    cout << "n : " << n << endl;

    std::ranges::empty_view<long> e;
    auto b = std::ranges::empty(e);
    cout << b << endl;
    static_assert(0 == e.size());
    static_assert(nullptr == e.data());
    static_assert(nullptr == e.begin());
    static_assert(nullptr == e.end());
    static_assert( 0 == 0);


    constexpr std::ranges::single_view sv1{3.1515};

    static_assert(sv1);
    static_assert(not sv1.empty());

    std::cout << *sv1.data() << endl;
    cout << *sv1.begin() << endl;
    cout << sv1.size() << endl;
    cout << std::distance(sv1.begin(), sv1.end()) << endl;


    string str{"C++\"20"};
    cout << std::quoted(str) << endl;
    std::ranges::single_view sv2{std::move(str)};
    cout << std::quoted(*sv2.data()) << endl;




}


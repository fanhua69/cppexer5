//
//  range_2.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-18.
//

#include <stdio.h>

#include <iostream>
#include <ranges>
#include <vector>
 
template<typename T>
struct range_t : private T
{
    using T::begin, T::end;
};
static_assert(std::ranges::range<range_t<std::vector<int>>>);
 
template<typename T>
struct scalar_t
{
    T t {}; /* no begin/end */
};
static_assert(not std::ranges::range<scalar_t<int>>);
 
void range_2_main()
{
    range_t<std::vector<int>> r;
    if constexpr (std::ranges::range<decltype(r)>)
        std::cout << "r is a range\n";

    scalar_t<int> s;
    if constexpr (std::ranges::range<std::vector<int>>)
        std::cout << "s is not a range\n";
}

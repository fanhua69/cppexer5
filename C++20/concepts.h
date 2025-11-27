//
//  concepts.h
//  testcpp3
//
//  Created by hua fan on 2025-06-22.
//
#include <algorithm>

template <typename T>
concept Sortable = requires(T a)
{
    std::ranges::sort(a);
};

template<typename T>
concept Sortable2 = std::ranges::random_access_range<T> &&
                    std::sortable<std::ranges::iterator_t<T>>;


template <typename T>
requires Sortable<T>
void sort1(T&c)
{}

template <Sortable T>
void sort2(T &c)
{}

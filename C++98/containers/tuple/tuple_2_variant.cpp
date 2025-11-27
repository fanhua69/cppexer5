//
//  tuple_2_variant.cpp
//  testcpp3
//
//  Created by hua fan on 2024-02-01.
//

#include <stdio.h>
#include "headers.h"
#include "variant"

// https://changkun.de/modern-cpp/zh-cn/04-containers/#4-2-%E6%97%A0%E5%BA%8F%E5%AE%B9%E5%99%A8
//运行期索引

template <size_t n, typename ... T>
constexpr std::variant<T...> _tuple_index(const std::tuple<T...>& tpl, size_t i )
{
    if constexpr(n >= sizeof...(T))
        throw std::out_of_range("out of range");

    if(i == n)
        return std::variant<T...>{std::in_place_index<n>, std::get<n>(tpl)};

    return _tuple_index<(n < sizeof...(T) - 1 ? n + 1 : 0)> (tpl,i);
}

template <typename ... T>
constexpr std::variant<T...> tuple_index(const std::tuple<T...>&tpl, size_t i)
{
    return _tuple_index<0>(tpl, i);
}

template <typename T0, typename ... Ts>
std::ostream & operator << (std::ostream &s, std::variant<T0, Ts...> const &v)
{
    std::visit([&](auto && x) { s << x; }, v);
    return s;
}


void tuple_2_main()
{
    std::tuple<int,string> s = {1, "wrewqrwe"};
    int i = 1;
    std::cout << tuple_index (s, i ) << endl;
}

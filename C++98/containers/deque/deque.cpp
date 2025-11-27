//
//  deque.cpp
//  testcpp2
//
//  Created by hua fan on 2023-09-07.
//

#include <stdio.h>

#include <deque>
#include <string_view>
#include <iostream>
#include <numeric>

void print_container(std::string_view       comment,
                    const std::deque<char> &c)
{
    std::cout << comment << "{";

    for(char x : c)
        std::cout << x << ' ';

    std::cout << "}\n";
}

void dequeMain()
{
    std::deque<char> cnt(10);

    std::iota(cnt.begin(), cnt.end(), '0');
}

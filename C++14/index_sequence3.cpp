//
//  index_sequence3.cpp
//  testcpp3
//
//  Created by hua fan on 2024-03-30.
//

#include <stdio.h>
#include <utility>
#include <vector>

template<size_t... N>
void print(std::index_sequence<N...>)
{
    std::vector<int> res;

}

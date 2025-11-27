//
//  alignas.cpp
//  testcpp3
//
//  Created by hua fan on 2024-02-11.
//

#include <stdio.h>
#include <iostream>

struct Storage {
    char      a;
    int       b;
    double    c;
    long long d;
};

struct alignas(std::max_align_t) AlignasStorage {
    char      a;
    int       b;
    double    c;
    long long d;
};

void alignas_main()
{
    std::cout << alignof(Storage) << std::endl;
    std::cout << alignof(AlignasStorage) << std::endl;
}

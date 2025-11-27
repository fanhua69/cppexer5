//
//  bitfield.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-31.
//

#include <stdio.h>
#include "headers.h"

struct alignas(4) test
{
    unsigned int a : 2 = 10;
};

void bitfield_main()
{
    cout << sizeof(test) << endl;
}

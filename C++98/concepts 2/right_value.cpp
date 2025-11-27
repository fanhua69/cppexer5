//
//  right_value.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-31.
//

#include <stdio.h>
#include "headers.h"


void inc(int &&v)
{
    v++;
}

void right_value_main()
{
    const int &a = std::move(1);
    int s = 1;
    cout << "before: s : " << s << endl;
    inc(std::move(10));
    cout << s << endl;
}

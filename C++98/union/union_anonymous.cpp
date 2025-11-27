//
//  union_anonymous.cpp
//  testcpp3
//
//  Created by hua fan on 2023-12-29.
//

#include <stdio.h>
#include "headers.h"

void union_anonymous_main()
{
    union
    {
        int a;
        const int *p;
    };

    a = 1;
    int b = 10;
    p = &a;
    cout << p << endl;
    cout << a << endl;
    cout << *p << endl;
}

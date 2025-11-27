//
//  closure.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-31.
//

#include <stdio.h>
#include "headers.h"

using foo = void(int);

void functional( void (*f)(int) )
{
    f(1);
}

void functional2( void(*f)(int))
{
    f(1);
}

void functional3( foo f )
{
    f(1);
}


void f2(int n)
{
    cout << n * 2 << endl;
}

void closure_main()
{

    auto f = [](int value)
    {
        cout << value << endl;
    };

    functional2(f);
    functional2(f2);
    f(1);
}

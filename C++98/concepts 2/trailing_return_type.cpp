//
//  trailing_return_type.cpp
//  testcpp3
//
//  Created by hua fan on 2024-02-17.
//

#include <stdio.h>
#include "headers.h"

template <typename T, typename U>
decltype((*(T*)0)+(*(U*)0)) add(T t, U u)
{
    return t+u;
}

template <typename T , typename U>
auto add2(T t, U u) ->decltype(t+u)
{
    return t + u;
}


int &foo(int & i);
float foo(float &f);

template <typename T>
auto func(T &val) ->decltype(foo(val))
{
    return foo(val);
}

void trailing_return_type_main()
{
    int a =1;
    float b = 2.0;
    auto c = add <float, int> (a, b);
    cout << c << endl;

    auto c2 = add2(a, b);
    cout << c2 << endl;

}

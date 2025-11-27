//
//  variadicTemplate.cpp
//  testcpp2
//
//  Created by hua fan on 2023-11-10.
//

#include <stdio.h>
#include "headers.h"

template <class ... Args>
auto adds(Args ... args)
{
    ( cout << ... << args ) << endl;
    cout << sizeof...(args) << endl;
}


auto f(auto ... args)
{
    return (... - args);
}

// binary left fold:
template<typename ... Ts>
auto f2(int num, Ts... args)
{
    return (args - ... - num);
}

// binary right fold:
template<typename ... Ts>
auto f3(int num, Ts... args)
{
    return (num - ... - args);
}


void variadicTemplateMain()
{
     adds(1,2,3,5);
     cout << f2(4,5, 6) << endl;
}

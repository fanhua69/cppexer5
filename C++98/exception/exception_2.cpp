//
//  exception_2.cpp
//  testcpp3
//
//  Created by hua fan on 2024-02-10.
//

#include <stdio.h>
#include "headers.h"


void may_throw()
{
    throw true;
}

auto non_block_throw = []
{
    //throw true;
    return;
};

void no_throw() noexcept
{
    return;
}

auto block_throw = [] noexcept
{
    no_throw();
};

void exception_2_main()
{
    cout << boolalpha << noexcept(may_throw()) << endl
    << noexcept(no_throw()) << endl
    << noexcept(non_block_throw()) << endl
    << noexcept(block_throw()) << endl;


}



//
//  throw_main.cpp
//  testcpp3
//
//  Created by hua fan on 2023-12-27.
//

#include <stdio.h>
#include "headers.h"
#include <functional>
#include <algorithm>

void foo()
{
    try
    {
        throw 123;
    }
    catch (const std::exception& e)
    {
        cout << e.what() << endl;
    }
}

void exception_main()
{
    try
    {
        foo();
    }
    catch(int n)
    {
        cout << "Caught" << endl;
    }

}

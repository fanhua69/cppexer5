//
//  parameter.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-07.
//

#include <stdio.h>
#include "headers.h"

void paramteter_test_fun(int n, int m)
{
};

int fun1()
{
    cout << "fun1 " << endl;
    return 1;
}

int fun2()
{
    cout << "fun2 " << endl;
    return 2;
}

void paramteter_test_fun_main()
{
    paramteter_test_fun(fun1(), fun2());
}

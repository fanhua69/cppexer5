//
//  function_overloading.cpp
//  testcpp3
//
//  Created by hua fan on 2023-12-30.
//

#include <stdio.h>
#include "headers.h"


void display(int a)
{
    cout << "Displaying  int : " << a << endl;
}

void display(double a)
{
    cout << "Displaying double : " << a << endl;
}

void function_overloading_main()
{
    int a = 10;

    display(a);

    double b = 20;
    display(b);

    display(10);
    display(10.0);
}

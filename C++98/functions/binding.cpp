//
//  binding.cpp
//  testcpp3
//
//  Created by hua fan on 2023-12-31.
//

#include <stdio.h>
#include "headers.h"
#include <functional>


static double func(int a, float b, double c, string d)
{
    cout << "in function: " << d << endl;
    return a + b + c;
}


static void func2(int &a, int &b)
{
    std::cout << "call f()" << std::endl;
     ++a;
     ++b;
     std::cout << "a: " << &a << ", " << a << std::endl;
     std::cout << "b: " << &b << ", " << b << std::endl;

}


void binding_main()
{
    auto f = std::bind(&func2, std::placeholders::_1, std::placeholders::_2);

    int a = 0, b = 0;
    int & ra = a;

    std::cout << "before call f()" << std::endl;
    std::cout << "a: " << &a << ", " << a << std::endl;
    std::cout << "b: " << &b << ", " << b << std::endl;

    f(a, std::ref(b));

    std::cout << "after call f()" << std::endl;
    std::cout << "a: " << &a << ", " << a << std::endl;
    std::cout << "b: " << &b << ", " << b << std::endl;

}

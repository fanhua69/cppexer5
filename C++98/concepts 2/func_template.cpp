//
//  func_template.cpp
//  testcpp3
//
//  Created by hua fan on 2024-02-17.
//

#include <stdio.h>
#include "headers.h"

template <typename T, typename U = int, U N = 0>
struct FooFunc
{

};

template <typename T = int>
void func(T a)
{
    cout << a << endl;

}

void func_template_main()
{
    func(11123);

}

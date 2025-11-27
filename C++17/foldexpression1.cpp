//
//  foldexpression1.cpp
//  testcpp3
//
//  Created by hua fan on 2025-06-26.
//

#include "headers_2.h"
#include <iostream>
#include "foldexpression1.h"
using namespace std;


template <typename ... Args>
void test (Args... args)
{
    ((printf("%d ", args)), ...);
    cout << endl;
    cout << (... + args) << endl;
    cout << (args + ...) << endl;
}

    
void foldexpression1_main()
{
    test(1,2,3,4,5);
}

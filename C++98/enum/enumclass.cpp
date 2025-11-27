//
//  enumclass.cpp
//  testcpp3
//
//  Created by hua fan on 2023-12-27.
//

#include <stdio.h>
#include "headers.h"

enum class Animals
{
    Bear,
    Cat,
    Chicken
};

enum class Birds
{
    Eagle,
    Duck,
    Chicken
};


void enum_class_main()
{
    Animals a;
    cout << (int) a << endl;
    cout << (int)Animals::Chicken << endl;
    a = Animals::Chicken;

    cout << (int)Birds::Chicken << endl;
}

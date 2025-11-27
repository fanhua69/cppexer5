//
//  literals.cpp
//  testcpp3
//
//  Created by hua fan on 2024-02-11.
//

#include <stdio.h>
#include <iostream>
#include "headers.h"
#include <string>



std::string operator "" _Pound (const char *p1, size_t l)
{
    return std::string(p1) + " Pount";
}

long operator "" _kg ( unsigned long long x)
{
    return x * 1000;
}

long double operator "" _mg (long double x)
{
    return  x / 1000;
}

void raw_string_literals_main()
{
    string s = R"AAA()AAA";
    cout << s << endl;

    string su = "123"_Pound;
    cout << su << endl;

    cout << 1_kg / 1.2_mg << endl;
}

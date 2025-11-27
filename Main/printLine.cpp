//
//  printLine.cpp
//  testcpp3
//
//  Created by hua fan on 2024-03-31.
//

#include <stdio.h>
#include "headers.h"


constexpr int lineLength = 40;

void printThickLine()
{
    std::string s (lineLength, '=');
    cout << s << endl;
}

void printThinLine()
{
    std::string s (lineLength, '-');
    cout << s << endl;
}

#include "headers_2.h"
#include <iostream>
using namespace std;

void printLine_main()
{
}

//
//  stringview1.cpp
//  testcpp2
//
//  Created by hua fan on 2023-11-10.
//

#include <stdio.h>
#include <string_view>
#include <string>
#include "headers.h"

void stringViewMain()
{
    std::string s = "hello world";
    std::string_view v{s};
    s[4] = 'H';
    cout << v << endl;
    cout << s << endl;

    string_view v2 = v.substr(1,2);
    cout << v2 << endl;
    cout << s << endl;
}


#include "headers_2.h"
#include <iostream>
using namespace std;

void stringview1_main()
{
}

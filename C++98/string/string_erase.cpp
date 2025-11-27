//
//  string_erase.cpp
//  testcpp3
//
//  Created by hua fan on 2025-09-19.
//


#include "headers_2.h"
#include <iostream>
using namespace std;

void string_erase_main()
{
    string s="1234567";
    s.erase(1,3);
    print(s);
    
    int a = 1;
    a = a++;
    cout << a << endl;
    
    a = 1;
    int b = a+++a;
    cout << b << endl;
}

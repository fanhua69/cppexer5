//
//  rvalue.cpp
//  testcpp2
//
//  Created by hua fan on 2023-11-11.
//

#include <stdio.h>
#include "headers.h"

string getName()
{
    return "aaaa";
}

void rvalueMain()
{
    string &&s = getName();
    s = "sdafs";

    string &&s2 =  getName();

    string *p = &s;
    cout << p << endl;
    cout << *p << endl;
    s[1]='b';
    cout << *p << endl;
    cout << &s2 << endl;
    *p = "asdf";
    cout <<*p << endl;
    cout << s << endl;



   // cout << sizeof(void) << endl;



}

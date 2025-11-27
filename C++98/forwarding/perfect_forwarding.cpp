//
//  perfect_forwarding.cpp
//  testcpp3
//
//  Created by hua fan on 2023-12-29.
//

#include <stdio.h>
#include "headers.h"

template <class T>
void show_type(T& t)
{
    cout << "lvalue:" << t << ", " <<  typeid(t).name() << endl;
}

template <class T>
void show_type(T&& t)
{
    cout << "rvalue:" << t << ", " << typeid(t).name() << endl;
}

template <class T>
void normal_forwarding(T &&t)
{
    show_type(std::forward<T>(t));
}

string get_string()
{
    return "hello world right ";
}

void perfect_forwarding_main()
{
    string s = "left value hello world";
    normal_forwarding(s);
    normal_forwarding(get_string());
}

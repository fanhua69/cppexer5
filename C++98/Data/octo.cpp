//
//  octo.cpp
//  testcpp2
//
//  Created by hua fan on 2023-11-01.
//

#include <stdio.h>
#include "headers.h"
#include <algorithm>
#include <functional>


int fff(int n)
{
    return n - 10;
}

template <typename T>
T func2(T a)
{
    return a+2;
}

struct add
{
    int operator()(int x)
    {
        return x + 9;
    }
};

template <typename T>
struct sub
{
    T operator () (T a)
    {
        return a - 8;
    }
};

template <typename T>
struct foo2
{
    static T foo(T a)
    {
        return a * 4;
    }
};

struct foo1
{
    static int foo(int a)
    {
        return a * 3;
    }
};

auto func3 = [](int a) { return a * 2;};


struct foo3
{
    int foo(int a)
    {
        return a*a;
    }
};

void octoMain()
{
    std::function<int(int)> f;

    f = fff;
    cout <<f(110) << endl;

    f = func2<int>;
    cout << f(11) << endl;

    f = sub<int>();
    cout << f(11) << endl;

    f = foo2<int>::foo;
    cout << f(11) << endl;

    f=add();
    cout << f(11) << endl;

    f=func3;
    cout << f(11) << endl;

    f= foo1::foo;
    cout << f(11) << endl;

    foo3 tf;
    f = std::bind(&foo3::foo, tf, std::placeholders::_1);
    cout << f(11) << endl;

    std::function<int(int)> f2;
    f2 = f;
    cout << f2(11) << endl;

    f2 = std::move(f);
    cout << f2(11) << endl;

    std::function<int(int)> f3(f);
    cout << f3(11) << endl;
}

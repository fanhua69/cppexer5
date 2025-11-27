//
//  coroutines.cpp
//  testcpp3
//
//  Created by hua fan on 2024-02-26.
//

#include <stdio.h>
#include "headers.h"
#include <coroutine>
#include <iostream>
 
//generator<int>
//range(int start, int end)
//{
//    while(start < end)
//    {
//        co_yield start;
//        start++;
//    }
//}


class basea
{
    public :
        void test(int a)
        {
            cout << " base " << endl;
        }
};

class db : public basea
{
    public :
        void test()
        {
            cout << "d c " << endl;
        }

        int d;
        int c;
};

void fff(basea &a)
{
    a.test(2);
}

void coroutines_main()
{
    db a;
    fff(a);

    // Designated initializers:
    db aa{.c =10, .d = 20};
    print(aa.c);
    print(aa.d);

    // Template Syntax for lambdas:
    auto l = []<typename T>(T a) { return a * 10;};
    cout << l(10) << endl;
    cout << l(123.1234) << endl;

    int n = 0;
    int m = 1;
    const int &r = n;
    decltype((r)) a3 = m;
    cout << "r: " << typeid(r).name() << endl;

    cout <<"a3:" << typeid(a3).name() << endl;

    enum class Color
    {
        red, blue,green
    };

    int x = (int)(Color::red);
    Color y = static_cast<Color>(2);
    Color z = Color::red;


    for (vector<int> v{1,2,3}; auto a: v)
    {
    cout << a << endl;
    }
}

//
//  testcpp17.cpp
//  testcpp3
//
//  Created by hua fan on 2024-02-24.
//

#include <stdio.h>
#include "headers.h"

class structbinding
{
public:
    structbinding(auto s, auto n ) : s(s), n(n)
    {}
    string s;
    int n;

    static int a;
};

int structbinding::a = 3333;

int nn =2312;

template <int *arg>
void foo()
{
    cout << *arg << endl;
}


template <int>
void foo()
{
    cout << "est int" << endl;
}

void testcpp17()
{
    cout << "test cpp1 7 " << endl;
    print("dsafsdf");

    structbinding a{"sdfd", 1123};
    auto [c,b]{a};
    print(c);
    print(b);

    foo<&structbinding::a> ();
    foo<&nn> ();
}

void test_va_start(string s, int n, ...)
{
    va_list vl;
    va_start(vl, n);
    cout << "string :" << n << endl;

    int N = va_arg(vl, int);
    cout << "number:" << N << endl;

    for(int i = 0; i < N ; i ++)
    {
        //cout << va_arg(vl, int ) << endl;
    }
    va_end(vl);
}

template <typename T>
constexpr T pi = T(3.1415936);

void structured_binding_3_main()
{
    double d = pi<double> ;
    int dd = pi<int>;

}

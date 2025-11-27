//
//  sfinae3.cpp
//  testcpp3
//
//  Created by hua fan on 2025-10-24.
//

#include <type_traits>
#include <iostream>

using namespace std;

namespace
{

template <typename T>
enable_if_t<is_integral_v<T>, void> foo(T t)
{
    cout << "is int" << endl;
}

template <typename T>
enable_if_t<is_floating_point_v<T> , void> foo(T t)
{
    cout << "is float " << endl;
}

template <typename T>
struct Foo {
    // 仅当 T 是整数类型时，定义该函数
    void bar() requires integral<T>
    {
        cout << "Integral bar()" << endl;
    }

    // 仅当 T 是浮点类型时，定义该函数
    void bar() requires floating_point<T>
    {
        cout << "Floating bar()" << endl;
    }
};


template <bool B, typename T = void>
using enable_if_tt = typename enable_if<B, T>::type;

constexpr int x = 2 * 3;
constexpr int add(int a, int b)
{
    return a + b;
}

struct C
{
    constexpr C(int x):v(x)
    {
    }
    int v;
};

}

#include "headers_2.h"
#include <iostream>
using namespace std;

void sfinae3_main()
{
    foo(123);
    foo(11.11);
    int a = 1;
    int b = 3;
    cout << add(a,b) << endl;
    int N = add(1,3);
    int arr [N];

    C c(1);
    int n = 10;
    C cc(n);
    int arr2[cc.v];
}

//
//  universal_reference.cpp
//  testcpp3
//
//  Created by hua fan on 2023-12-30.
//

#include <stdio.h>
#include "headers.h"


static void bar (int &a)
{
    cout << "left value: " << a << ", type: " << typeid(a).name() << endl;
}

static void bar (int &&a)
{
    cout << "right value: " << a << ", type: " << typeid(a).name() << endl;
}



template <class T>
static void foo(const T& a)
{
    //bar(std::forward<T>(a));
    cout << "left or right value: " << a << ", type: " << typeid(a).name() << endl;
}

void univeral_reference_main()
{
    int a = 10;
    foo(a);

    foo(20);

}

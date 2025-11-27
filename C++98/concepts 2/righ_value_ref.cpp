//
//  righ_value_ref.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-31.
//

#include <stdio.h>
#include "headers.h"

static void ref(int &v)
{
    cout << "left value : " << v << endl;
}

static void ref(int &&v)
{
    cout << "right value : " << v << endl;
}

template <typename T>
void pass(T && v)
{
    cout << "Normal Template && pass: " ;
    ref(v);

    cout << "using forwart<T> :";
    ref(std::forward<T>(v));

    cout << "using move :";
    ref(std::move(v));

    cout << "using static_cast<T&&> :";
    ref(static_cast<T&&>(v));





}

void right_value_ref_main()
{
    cout << "Pass right value :" << endl;
    pass(1);

    cout << "Pass left value:" << endl;
    int l = 1;
    pass(l);
    
}


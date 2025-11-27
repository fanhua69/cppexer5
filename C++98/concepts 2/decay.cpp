//
//  decay.cpp
//  testcpp3
//
//  Created by hua fan on 2024-02-26.
//

#include <stdio.h>
#include "headers.h"

void callback(int a)
{
    cout << a << endl;
}

void call(void callback(int), int x)
{
    cout << typeid(callback).name() << endl;
    callback(x);
    (*callback)(x);
}

void callArray( int s[100])
{
    cout << sizeof(s) << endl;
    cout << typeid(s).name() << endl;
}

void decay_main()
{
    cout << typeid(callback).name() << endl;
    call(callback, 10);

    int n[10];
    callArray(n);

}

//
//  atomic_int.cpp
//  testcpp3
//
//  Created by hua fan on 2023-12-27.
//

#include <stdio.h>
#include <atomic>
#include "headers.h"

void atomic_int_main()
{
    std::atomic_int a = 1;
    a.load();
    int n = a.fetch_add(20);
    cout << "fetch return: " << n << endl;
    std::atomic_int b = 55;
    auto c = a.exchange(b);
    cout << typeid(c).name() << endl;
    cout << typeid(a).name() << endl;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;

}

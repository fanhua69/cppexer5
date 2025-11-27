//
//  duration_test_2.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-01.
//

#include <stdio.h>
#include <chrono>
#include "headers.h"


static void foo()
{
    for(int i = 0; i < 1000; i++)
    {
        int n = i * 234 *2314 * 324;
    }
}

void duration_test_2_main()
{
    std::chrono::time_point p1 = std::chrono::steady_clock::now();
    foo();
    std::chrono::time_point p2 = std::chrono::steady_clock::now();

    duration<double, micro> d1 = p2 - p1;
    duration<double, milli> d2 = p2 - p1;
    std::chrono::seconds s1 = std::chrono::duration_cast<std::chrono::seconds> (p2-p1); // cannot convert to int , s1 is int;

    cout << typeid(d1).name() << endl;

    cout << d1.count() << endl;

}


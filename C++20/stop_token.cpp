//
//  stop_token.cpp
//  testcpp3
//
//  Created by hua fan on 2025-09-08.
//

#include "headers_2.h"
#include <iostream>
using namespace std;
#include <thread>
#include <stop_token>
#include <chrono>

namespace
{
template <integral T>
T sum(T a, T b)
{
    return a + b;
}
}

void stop_token_main()
{
    cout << sum(1,2) << endl;
}

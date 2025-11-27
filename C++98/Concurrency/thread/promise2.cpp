//
//  promise2.cpp
//  testcpp3
//
//  Created by hua fan on 2025-09-23.
//


#include "headers_2.h"
#include <iostream>
#include <future>

using namespace std;

void promise2_main()
{
    std::promise<int> pro;
    std::future<int> fut = pro.get_future();
    pro.set_value(134);
    int a = fut.get();
    cout << a << endl;
    
    
}

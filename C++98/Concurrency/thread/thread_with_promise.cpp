//
//  thread_with_promise.cpp
//  testcpp3
//
//  Created by hua fan on 2025-11-07.
//


#include "headers_2.h"
#include <iostream>
#include <future>

using namespace std;

#include <thread>

namespace
{

int func(float f)
{
    return f* 10;
}

}


void thread_with_promise_main()
{
    std::packaged_task<int(float)> p(func);
    std::future<int> fu = p.get_future();
    
    std::thread t(std::move(p),1234.234f);
    
    int n = fu.get();
    cout << n << endl;
    t.join();
}

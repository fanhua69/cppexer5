//
//  thread_future.cpp
//  testcpp3
//
//  Created by hua fan on 2025-10-24.
//


#include "headers_2.h"
#include <iostream>
#include <future>
using namespace std;



void worker(std::promise<int> p, int n)
{
    int result = n * 2;
    p.set_value(result);
}

void thread_future_main()
{
    std::promise<int> p;
    std::future<int> f = p.get_future();
    
    std::thread t(worker, std::move(p), 111);
    cout << f.get() << endl;
    t.join();
}

//
//  shared_mutex.cpp
//  testcpp3
//
//  Created by hua fan on 2025-09-08.
//

#include "headers_2.h"
#include <iostream>
#include <thread>

using namespace std;

#include <shared_mutex>

std::shared_mutex shared_mutex_mu;
string shared_mutex_data;

void reader()
{
    std::shared_lock<std::shared_mutex> lock(shared_mutex_mu);
    auto s = shared_mutex_data;
}

void writer()
{
    std::unique_lock<shared_mutex> lk(shared_mutex_mu);
    shared_mutex_data = "aaaa";
}
    
void shared_mutex_main()
{
    thread t2[10];
    for(int i = 0; i < 10; i++)
        t2[i] = thread(reader);

    thread tw[10];
    for(int i =0;i < 10; i++)
        tw[i] = thread(writer);
    
    for(int i = 0; i  < 10; i ++)
    {
        t2[i].join();
        tw[i].join();
    }

    
}

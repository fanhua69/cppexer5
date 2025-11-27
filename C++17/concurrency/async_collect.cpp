//
//  async_collect.cpp
//  testcpp3
//
//  Created by hua fan on 2025-09-16.
//


#include "headers_2.h"
#include <iostream>
#include <mutex>
#include <future>
#include <thread>

using namespace std;

namespace
{

thread_local int thread_local_counter;
std::mutex coutlock;

int worker(int id)
{
    for(int i = 0; i < 5; ++i)
    {
        thread_local_counter ++;
        {
            std::unique_lock<std::mutex> lk(coutlock);
            cout << "Thread : " << id << ", thread_local counter:" << thread_local_counter << endl;
        }
    }
    
    return thread_local_counter;
}


}

void async_collect_main()
{
    vector<std::future<int>> gc;
    for(int i = 0; i < 5; ++i)
    {
        gc.push_back(std::async(std::launch::async, worker, i));
    }

    
    int sum = 0;
    for(auto &f : gc)
        sum+=f.get();
    
    cout << sum << endl;
}

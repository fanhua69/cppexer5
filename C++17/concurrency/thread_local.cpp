//
//  thread_local.cpp
//  testcpp3
//
//  Created by hua fan on 2025-09-16.
//


#include "headers_2.h"
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

namespace
{

thread_local int tls_counter = 0;
std::mutex m_coutmt;

std::vector<int> counters;

void worker(int id)
{
    for(int i = 0; i < 5; ++i)
    {
        tls_counter  += 1;
        
        {
            std::unique_lock<mutex> lk(m_coutmt);
            cout << "Thread " << id << "Counter " << tls_counter << endl;
        }
    }

    {
        std::unique_lock<mutex> lk(m_coutmt);
        counters.push_back(tls_counter);
    }
}


}

void thread_local_main()
{
    vector<thread> threads;
    for(int i = 0; i < 5; ++i)
    {
        threads.emplace_back(worker, i );
    }
    
    for(auto &t: threads)
    {
        t.join();
    }
    
    int sum = 0;
    for(auto n : counters)
        sum+=n;
    
    cout << sum << endl;
    return;
}

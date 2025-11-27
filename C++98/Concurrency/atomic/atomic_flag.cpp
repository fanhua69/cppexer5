//
//  atomic_flag.cpp
//  testcpp3
//
//  Created by hua fan on 2025-09-19.
//

#include "headers_2.h"
#include <iostream>
#include <atomic>
#include <thread>

using namespace std;

namespace
{
std::atomic_flag f = ATOMIC_FLAG_INIT;
int g=0;

void mylock()
{
    while(f.test_and_set());
}
void unlock()
{
    f.clear();
}

void job(int id)
{
    while(g < 1000)
    {
        mylock();
        g++;
        cout << "id:" << id << ", data:" << g << endl;
        unlock();
    }
}

}



void atomic_flag_main()
{
    vector<std::thread> ts;
    for(int i = 0; i < 10; ++i)
    {
        ts.emplace_back(job, i);
    }
    
    for(auto &t :ts)
        t.join();
}

//
//  classfunction.cpp
//  testcpp3
//
//  Created by hua fan on 2025-09-16.
//


#include "headers_2.h"
#include <iostream>
#include <iomanip>
#include <iostream>
#include <exception>
#include <thread>
#include <mutex>

using namespace std;

namespace
{
atomic<int> gData = 0;
int target = 1000;

std::mutex mt;

void job(int id)
{
    while(true)
    {
        int expected = 0;
        do
        {
            //this_thread::sleep_for(100ms);
            expected = gData.load();
        }while(!gData.compare_exchange_weak(expected, expected+1));
        
        {
            std::unique_lock<mutex> lk(mt);
            cout << "Current value:" << gData.load() << " in id:" << id << endl;
        }
        
        if(gData.load() >= target)
        {
            return;
        }
    }
}

void job_strong(int id)
{
    int expected = gData.load();
    while(expected < target)
    {
        gData.compare_exchange_strong(expected, expected + 1);
        {
            std::lock_guard<mutex> lg(mt);
            cout << "id : " << id << " value : " << gData.load() << endl;
        }
    }
}

}

void classfunction_main()
{
    std::vector<thread> ts;
    for(int i = 0; i < 5; ++i)
        ts.emplace_back(job_strong, i);
    
    for(auto &t: ts)
        t.join();
    
}


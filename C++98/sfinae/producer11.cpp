//
//  producer11.cpp
//  testcpp3
//
//  Created by hua fan on 2025-10-24.
//


#include "headers_2.h"
#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>

using namespace std;


namespace
{
std::vector<int> data;
atomic<bool> job_done = false;
std::mutex mt;
std::condition_variable cv;

void producer(int n)
{
    for(int i = 0; i < n; i++)
    {
        std::unique_lock<mutex> lk(mt);
        cv.wait(lk, [](){return data.empty();});
        data.push_back(i);
        cout << "Pushing data: " << i << endl;
        cv.notify_one();
    }
    
    job_done = true;
}

void consumer()
{
    while(!job_done ||  !data.empty())
    {
        std::unique_lock<mutex> lk(mt);
        cv.wait(lk, [](){return !data.empty() || job_done.load();});
        if(data.size())
        {
            cout << "Consuming data" << data.back() << endl;
            data.pop_back();
            cv.notify_one();
        }
    }
}

}

void producer11_main()
{
    std::thread tp(producer, 100);
    std::thread tc(consumer);
    tp.join();
    tc.join();
}

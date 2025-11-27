//
//  condition_variable.cpp
//  testcpp3
//
//  Created by hua fan on 2023-12-31.
//

#include <stdio.h>
#include "headers.h"
#include <condition_variable>
#include <thread>
#include <mutex>

std::deque<int> q;
std::mutex g_mutex;
std::condition_variable condFeed;
std::condition_variable condCons;

void function1()
{
    int count = 100;
    while(count > 0)
    {
        std::unique_lock<std::mutex> locker(g_mutex);
        if(!q.empty())
        {
            condFeed.wait(locker);
        }

        q.push_back(count);
        locker.unlock();
        cout << "Feed : " << count << endl;
        condCons.notify_one();

        count --;
    }
}

void function2()
{
    int data = 0;
    while(data!= 1)
    {
        std::unique_lock<std::mutex> locker(g_mutex);
        while (q.empty())
        {
            condCons.wait(locker);
        }

        data = q.back();
        q.pop_back();
        locker.unlock();
        cout << " got value " << data << endl;
        condFeed.notify_one();
    }
}

void condition_variable_main()
{
    std::thread t1(function1);
    std::thread t2(function2);

    t1.join();
    t2.join();

    return;
}



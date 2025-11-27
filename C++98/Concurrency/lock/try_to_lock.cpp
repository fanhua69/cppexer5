//
//  try_to_lock.cpp
//  testcpp3
//
//  Created by hua fan on 2023-12-31.
//

#include <stdio.h>
#include <mutex>
#include <chrono>
#include <list>
#include <thread>
#include <iostream>

static std::mutex g_mutex;
static std::list<int> g_list;

void consumer()
{
    while(true)
    {
        std::unique_lock<std::mutex> locker(g_mutex);
        std::chrono::milliseconds time(20);

       //std::this_thread::sleep_for(time);

        if(!g_list.empty())
        {
            if(g_list.front() == -1)
            {
                break;
            }
            std::cout << "Getting: " <<  g_list.front() << std::endl;
            g_list.pop_front();
        }
    }
}

void producer()
{
    int i = 0;
    while(i < 100000)
    {
        std::unique_lock<std::mutex> locker(g_mutex, std::try_to_lock);
        if(locker.owns_lock())
        {
            g_list.push_back(i==99999 ? -1 : i);
            std::cout << "producing: " << i << std::endl;
            i++;
        }
        else
        {
            std::cout << "Cannot get mutex" << std::endl;
        }
    }
}

void try_to_lock_main()
{
    std::thread th1(consumer);
    std::thread th2(producer);

    th1.join();
    th2.join();
}



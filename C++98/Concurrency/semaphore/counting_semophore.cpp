//
//  counting_semophore.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-03.
//

#include <stdio.h>
#include <semaphore>
#include <list>
#include <thread>
#include "headers.h"

static std::counting_semaphore<1> g_semaphore(0);
static std::list<int> g_data;


static std::mutex g_mutex_cout;
static std::mutex g_mutex_data;

static void producer()
{
    int count = 0;
    while(count < 1000)
    {
        if(!g_semaphore.try_acquire())
        {
            std::unique_lock<std::mutex> lockerdata(g_mutex_data);
            g_data.push_back(count++);
            cout << "Producing: " << g_data.back() << endl;
            lockerdata.unlock();
        }
    }
}

static void completeWork()
{
    while(true)
    {
        if(g_semaphore.try_acquire())
        {
            std::unique_lock<std::mutex> lock(g_mutex_data);
            cout << "Consuming:  " << g_data.back() << endl;

            if(g_data.back() == 9)
                break;
            g_data.pop_back();

            g_semaphore.release();
        }
    }
}


void counting_semaphore_main()
{
    std::thread th1(producer);
    std::thread th2(completeWork);

    th1.join();
    th2.join();

}


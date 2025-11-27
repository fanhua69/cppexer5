//
//  mutex.cpp
//  testcpp3
//
//  Created by hua fan on 2023-12-31.
//

#include <stdio.h>
#include "headers.h"
#include <mutex>
#include <list>
#include <thread>
#include <chrono>

list<int> test_list;

mutex my_mutex;

constexpr unsigned long long total = 100000000000;

void in_list()
{
    for(int num = 0; num < total; num++)
    {
        my_mutex.lock();
        cout << "adding data: " << num << endl;
        test_list.push_back(num);
        my_mutex.unlock();
        this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void out_list()
{
    while(true)
    {
        while(test_list.size() > 0)
        {
            my_mutex.lock();
            cout << "Getting Data: " << test_list.back() << endl;
            test_list.pop_back();
            my_mutex.unlock();
            this_thread::sleep_for(chrono::seconds(1));
        }
    }
}

void mutex_main()
{
    std::thread th1(in_list);
    std::thread th2(out_list);
    th1.join();
    th2.join();
}

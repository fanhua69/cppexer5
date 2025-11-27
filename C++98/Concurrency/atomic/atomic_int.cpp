//
//  atomic_int.cpp
//  testcpp3
//
//  Created by hua fan on 2024-12-13.
//


#include <atomic>

#include <thread>
#include <mutex>
#include <iostream>

using namespace std;

std::atomic_int ga_total = 0;
int g_i = 0;

void thread1()
{
    for(int i = 0; i < 10000000; i ++)
    {
        ga_total.wait(12);
        ++g_i;
    }
}

void thread2()
{
    for(int i = 0; i < 10000000; i++)
    {
        ++ga_total;
        ++g_i;
    }
}

void atomic_main()
{
    std::thread t1(thread1);
    std::thread t2(thread2);
    t1.join();
    t2.join();

    cout << ga_total.load() << endl;
    cout << g_i << endl;
}

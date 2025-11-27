//
//  memory_order.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-02.
//

#include <stdio.h>
#include <thread>
#include <mutex>
#include "headers.h"

std::atomic<int> A = 0;
std::atomic<int> B = 0;

void th1()
{
    A = 42;
    this_thread::sleep_for(chrono::seconds(1));
    B.store(1) ; //, std::memory_order_release);
}

void th2()
{
    while(true)
    {
        if (B.load(/*std::memory_order_acquire*/) == 1)
        {
            std::cout << A << std::endl;
            break;
        }
    }
}

void memory_order_main()
{
    std::thread t2(th2);
    this_thread::sleep_for(chrono::milliseconds(1000));
    std::thread t1(th1);
    t1.join();
    t2.join();
}

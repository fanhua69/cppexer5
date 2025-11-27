//
//  jthreadmain.cpp
//  testcpp3
//
//  Created by hua fan on 2023-12-27.
//

#include <stdio.h>
#include <array>
#include <atomic>
#include <iostream>
#include <thread>

using namespace std;

std::atomic<long long> dataj{10};
std::array<long long, 5> return_values{};

void do_work(int thread_num)
{
    long long val = dataj.fetch_add(1,std::memory_order_relaxed);
    return_values[thread_num] = val;
}

void jthread_main()
{
    {
        std::thread th0{do_work, 0};
        std::thread th1{do_work, 1};
        std::thread th2{do_work, 2};
        std::thread th3{do_work, 3};
        std::thread th4{do_work, 4};
        th0.join();
        th1.join();
        th2.join();
        th3.join();
        th4.join();
    }

    cout << "Result:" << dataj << '\n';

    for(long long val : return_values)
        cout << "Seend values:" << val << endl;
}

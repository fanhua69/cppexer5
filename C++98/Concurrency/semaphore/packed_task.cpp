//
//  packaged_task.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-28.
//

#include <stdio.h>
#include <chrono>
#include <thread>
#include <future>
#include <chrono>
#include <iostream>
#include "headers.h"
#include <functional>
#include <cmath>

int task()
{
    std::this_thread::sleep_for(std::chrono::seconds(3));
    return 1;
}

int ffff(int x, int y)
{
    return std::pow(x,y);
}

void packaged_task_function()
{
    std::packaged_task <int(void)> t(task);
    std::future<int> f = t.get_future();

    t();

    cout << " called t " <<endl;

    std::cout << f.get() << std::endl;
}

void packaged_task_thread()
{
    std::packaged_task<int(int,int)> task4(ffff);
    std::future<int> r = task4.get_future();
    std::thread task_td (std::move(task4), 2, 10);
    task_td.join();
    cout << r.get() << endl;
}

void packaged_task_lambda()
{
    std::packaged_task<int(int,int)> task([](int a, int b) {
        return std::pow(a,b);
    });

    std::future <int> f = task.get_future();

    task(2,2);

    cout << f.get() << endl;
}

void packaged_task_bind()
{
    std::packaged_task<int()> task3(std::bind(ffff, 2,3));
    std::future <int> f3 = task3.get_future();
    task3();

    cout << f3.get() << endl;
}

void packaged_task_main()
{
    packaged_task_bind();
    packaged_task_lambda();
    packaged_task_function();
    packaged_task_thread();
}

//
//  pachaged_tasl2.cpp
//  testcpp3
//
//  Created by hua fan on 2025-09-23.
//


#include "headers_2.h"
#include <iostream>
#include <future>
#include <thread>

using namespace std;

namespace
{

int work()
{
    return 11;
}


void func1(std::packaged_task<int()> && task)
{
    task();
}

void func_future(std::future<int> && f)
{
    int a = f.get();
    cout << a << endl;
}

}

void pachaged_tasl2_main()
{
    packaged_task<int()> task(work);
    auto t2 = std::move(task);
    std::future<int> f = t2.get_future();
    t2();
    std::future<int> f2 = std::move(f);
    int a = f2.get();
    cout << a << endl;
}

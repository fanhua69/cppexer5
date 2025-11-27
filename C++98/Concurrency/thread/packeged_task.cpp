//
//  packeged_task.cpp
//  testcpp3
//
//  Created by hua fan on 2024-05-04.
//

#include <stdio.h>
#include <thread>
#include <future>
#include <iostream>

using namespace std;

int threadF()
{
    int n;
    cin >> n ;
    return n;
}

void thread2(std::future<int> f)
{
    if(f.valid())
    {
        cout << "Thread 2 : " << f.get() << endl;
    }
}

void thread1(packaged_task<int()> t)
{
    t();
}

void packeged_task_main()
{
    std::packaged_task<int()> t(threadF);
    std::future<int> f = t.get_future();

    std::thread t2(thread2, std::move(f));
    std::thread t1(thread1, std::move(t));


    t2.join();
    t1.join();

}

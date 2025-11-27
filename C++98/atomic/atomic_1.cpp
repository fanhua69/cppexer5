//
//  atomic_1.cpp
//  testcpp3
//
//  Created by hua fan on 2025-01-18.
//

#include <utility>
#include <atomic>
#include <iostream>
#include <thread>
#include <mutex>
#include <memory>

using namespace std;

std::mutex               mt_wait;
std::mutex               mt_atomic;
std::condition_variable  cv_atomic;
int g_data = 0;

void printNotification(int id, string info)
{
    std::lock_guard lg(mt_atomic);
    cout << "ID: " << id << " " << info << endl;
}

void thread_atomic_1(int id)
{
    printNotification(id, "thread starts");
    std::this_thread::sleep_for(500ms);
    g_data  = 1;

    for(int i = 0;  i < 20; i++)
    {
        this_thread::sleep_for(100ms);
        cv_atomic.notify_all();
    }
    printNotification(id, "thread end");
}



void thread_atomic_2(int id)
{
    printNotification(id, "thread starts");

    std::unique_lock<mutex> ul(mt_wait);
    while(g_data == 0)
    {
        cv_atomic.wait(ul, [](){return g_data != 0;});
    }


    printNotification(id, "thread ends");
}


std::unique_ptr<int> setdata()
{
    std::unique_ptr<int> p = make_unique<int>(22);
    return p;
}


void atomic_1_main()
{
    auto p = setdata();
    
    cout << *p << endl;


}

//
//  my_thread_pool.cpp
//  testcpp3
//
//  Created by hua fan on 2024-02-06.
//

#include <stdio.h>
#include "headers.h"
#include <thread>
#include <functional>
#include <chrono>
#include <queue>
#include <mutex>
#include <memory>
#include <vector>

namespace concurrency
{

std::mutex queue_mutex;
std::mutex cout_mutex;
std::condition_variable cond_work_ready;
std::mutex work_ready_mutex;


void print(string s)
{
    std::lock_guard<std::mutex> g(cout_mutex);
    cout << s << endl;
}


using F_Q = std::queue<std::function<void()>>;
F_Q g_queue;


void thread_func(int n)
{
    while(true)
    {
        std::unique_lock<std::mutex> lock(work_ready_mutex);
        cond_work_ready.wait(lock);

        std::function <void()> f;

        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            if(!g_queue.empty())
            {
                f = std::move(g_queue.front());
                g_queue.pop();
            }
        }

        lock.unlock();

        if(f)
        {
            print("Thread " + std::to_string(n) + " is working on ...");
            f();
        }
    }
}


class myThread : public std::thread
{
public:

    myThread(std::function<void()> f):
            std::thread(f)
    {}
};

class ThreadPool
{
public :
    std::vector<myThread> m_threads;
};

void work_func(int n)
{
    print( "working...: " + std::to_string(n));
    std::this_thread::sleep_for(chrono::seconds(1));
}

void my_thread_main()
{
    ThreadPool tp;
    for(int i = 0; i< 4; i++)
    {
        tp.m_threads.emplace_back(myThread(std::bind(thread_func, i)));
    }

    for(int i = 0; i < 10; i++)
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        g_queue.push(std::bind(work_func, i));
        print("pushing work : " + std::to_string(i));
        cond_work_ready.notify_all();
    }

    for(int i = 0; i< 4; i++)
    {
        tp.m_threads.back().join();
    }
}
}

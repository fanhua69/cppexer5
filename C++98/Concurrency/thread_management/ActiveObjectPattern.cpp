//
//  ActiveObjectPattern.cpp
//  testcpp3
//
//  Created by hua fan on 2025-05-30.
//

#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <atomic>

using namespace std;

// Activation Queue:
class ActivationQueue
{
private:
    std::queue<std::function<void()>> tasks;
    std::mutex mtx;
    std::condition_variable cv;
    bool shutdown = false;
    
public:
    void enqueue(std::function<void()> task)
    {
        {
            std::lock_guard<std::mutex> lock(mtx);
            tasks.push(task);
        }
        cv.notify_one();
    }
    
    std::function<void()> dequeue()
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock,
                [&](){
                    return !tasks.empty() || shutdown;
                });

        if(shutdown && tasks.empty())
            return nullptr;
        
        auto task = tasks.front();
        tasks.pop();
        return task;
    }
    
    void stop()
    {
        {
            std::lock_guard<std::mutex> lock(mtx);
            shutdown = true;
        }
        cv.notify_all();
    }
};

// Servant:
class Servant
{
public:
    void doWork(int x)
    {
        std::cout << "Doing work with " << x << " in thread " << std::this_thread::get_id() << endl;
    }
};

// Proxy(Active Object)
class ActiveObject
{
private:
    ActivationQueue queue;
    Servant servant;
    std::thread worker;
    std::atomic<bool> running{true};

public:
    
    ActiveObject()
    {
        worker = std::thread([&]()
                             {
            while(running)
            {
                auto task = queue.dequeue();
                if(task)
                    task();
            }
        });
    }
        
    ~ActiveObject()
    {
        queue.stop();
        running = false;
        if(worker.joinable())
            worker.join();
    }
    
    void doWork(int x)
    {
        queue.enqueue([=, this]()
                      {
            servant.doWork(x);
        });
    }
};

// Test
int active_object_main3()
{
    ActiveObject ao;
    for(int i = 0; i < 5; ++i)
    {
        ao.doWork(i);
    }
    
    std::this_thread::sleep_for(std::chrono::seconds(1));
    return 0;
}



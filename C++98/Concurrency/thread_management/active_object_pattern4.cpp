//
//  active_object_pattern4.cpp
//  testcpp3
//
//  Created by hua fan on 2025-05-30.
//

#include <queue>
#include <functional>
#include <utility>
#include <thread>
#include <iostream>
#include <future>


using namespace std;


class ActiveQueue4
{
private:
    std::queue<std::packaged_task<void()>> m_taskQueue;
    
public:
    void enqueue(std::packaged_task<void()> task)
    {
        m_taskQueue.push(std::move(task));
    }
    
    std::optional<std::packaged_task<void()>> dequeue()
    {
        if(!m_taskQueue.empty())
        {
            std::packaged_task<void()> t = std::move(m_taskQueue.front());
            m_taskQueue.pop();
            return t;
        }
        return std::nullopt;
    }
};


class ActiveObject4
{
    ActiveQueue4 m_activeQueue;
    std::thread m_thread;
    
public:
    ActiveObject4()
    {
        m_thread = std::thread(std::bind(&ActiveObject4::work, this));
    }
    
    ~ActiveObject4()
    {
        if(m_thread.joinable())
        {
            m_thread.join();
        }
    }
    
    void work()
    {
        while(true)
        {
            std::optional<std::packaged_task<void()>> f = m_activeQueue.dequeue();
            if(f!=std::nullopt && f->valid())
            {
                f.value()();
            }
            break;
        }
    }
    
    template <typename T, typename ... Args>
    void addTask(T &&func, Args ... args)
    {
        auto bindedFunc = std::bind(std::forward<T>(func), std::forward<Args>(args)...);
        std::packaged_task<void()> t(bindedFunc);
        m_activeQueue.enqueue(std::move(t));
    }
};

void avtive_object_pattern_4_main()
{
    ActiveObject4 ao;
    ao.addTask([](int i, int j){cout <<"working..." << endl; return i+j;}, 1,2);
    
    
    int a[5]={1,2,3,4,5};
    int *ptr=(int *)(&a+1);
    printf("%d\n", *ptr);
    printf("%d\n", *(a+1));
    
    printf("%d,%d",*(a+1),*(ptr-1));

}



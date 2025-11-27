//
//  threadpool3.cpp
//  testcpp3
//
//  Created by hua fan on 2025-09-13.
//


#include "headers_2.h"
#include <iostream>
#include <vector>
#include <thread>
#include <queue>
#include <future>
#include <functional>


using namespace std;


namespace
{
class ThreadPool
{
public:
    ThreadPool(int n)
    {
        for(int i = 0; i < n ;i++)
        {
            m_threads.push_back(std::thread(&ThreadPool::doJob, this));
        }
    }
    
    ~ThreadPool()
    {
        for(auto& t : m_threads)
        {
            if(t.joinable())
                t.join();
        }
    }
    
    ThreadPool(const ThreadPool &) = delete;
    ThreadPool & operator = (const ThreadPool&) = delete;
    ThreadPool(ThreadPool&&) = default;
    ThreadPool& operator = (ThreadPool &&) = default;
    
    template <typename Func, typename... Args>
    auto enqueue(Func&& f, Args&&... args)->std::future<std::invoke_result_t<Func, Args...>>
    {
        using RT = std::invoke_result_t<Func, Args...>;
        auto task = make_shared<packaged_task<RT()>>
        (
             [func = std::forward<Func>(f), ...args = std::forward<Args>(args)]() mutable
             {
                return func(args...);
             }
        );
        
        std::future<RT> fu = task->get_future();
        auto l = [task]() mutable
        {
            std::invoke(*task);
        };
        
        {
            std::unique_lock<mutex> lk(m_mt);
            m_tasks.push(l);
        }
        
        m_cv.notify_one();
        return fu;
    }
    
    void doJob()
    {
        while(true)
        {
            std::unique_lock<std::mutex> lk(m_mt);
            m_cv.wait(lk, [this](){return m_projectdone || !m_tasks.empty();});
            
            if(m_projectdone && m_tasks.empty())
            {
                break;
            }
            
            if(!m_tasks.empty())
            {
                std::function<void()> job = std::move(m_tasks.front());
                m_tasks.pop();
                lk.unlock();
                
                if(job)
                {
                    try
                    {
                        job();
                    }
                    catch(const std::exception &e)
                    {
                        cout << e.what() << endl;
                    }
                    catch(...)
                    {
                        cout << "Unknown exception " << endl;
                    }
                }
            }
        }
    }
    
    void shutdown()
    {
        {
            std::unique_lock<mutex> lk(m_mt);
            m_projectdone = true;
        }
            
        m_cv.notify_all();
    }
    
protected:
    vector<thread> m_threads;
    queue<std::function<void()>> m_tasks;
    std::mutex m_mt;
    std::condition_variable m_cv;
    bool m_projectdone = false;
};


//ThreadPool pool(5);
std::mutex g_mt;

int add(int a, int b)
{
    {
        std::unique_lock < mutex> lk(g_mt);
        cout << "in add " << a << ", " << b << endl;
        this_thread::sleep_for(200ms);
    }
    
    return a + b;
}

}

void threadpool3_main()
{
    for(int i = 0; i < 210; i++)
    {
 //       pool.enqueue(add, i, i * 2);
    }
    
 //   pool.shutdown();
    
}

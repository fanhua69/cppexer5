//
//  threadpool7.cpp
//  testcpp3
//
//  Created by hua fan on 2025-10-26.
//


#include "headers_2.h"
#include <iostream>
#include <thread>
#include <functional>
#include <future>
#include <queue>
#include <condition_variable>
#include <mutex>


using namespace std;

namespace
{

class ThreadPool
{
public:
    ThreadPool(int N) : m_project_done (false)
    {
        for(int i = 0; i < N; i++)
        {
            m_threads.emplace_back(&ThreadPool::doJob, this);
        }
    }
    
    ~ThreadPool()
    {
        shutdown();
        for(auto &t: m_threads)
        {
            if(t.joinable())
                t.join();
        }
    }
    
    template <typename FUNC, typename ... Args>
    auto enqueue(FUNC && func, Args&& ...args)->std::future<invoke_result_t<FUNC,Args...>>
    {
        using RT = std::invoke_result_t<FUNC, Args...>;
        
        auto l1 = [f = std::forward<FUNC> (func), ...argss = forward<Args>(args)]()->RT
        {
            std::invoke(f, argss...);
        };
        
        auto task = std::make_shared<std::packaged_task<RT()>>(l1);
        auto fu = task->get_future();
        auto ff = [task]()
        {
            std::invoke(*task);
        };
        
        m_function_queue.emplace(ff);
        return fu;
    }
    
    void doJob()
    {
        while(true)
        {
            std::unique_lock<mutex> lk(mt);
            m_cv.wait(lk, [this](){return m_project_done || !m_function_queue.empty();});
            
            if(m_project_done && !m_function_queue.empty())
                break;

            std::function<void()> job;
            if(m_function_queue.size())
            {
                job = std::move(m_function_queue.front());
                m_function_queue.pop();
            }
            
            if(job)
            {
                try
                {
                    job();
                }
                catch (const exception &e)
                {
                    cout << e.what() << endl;
                }
                catch(...)
                {
                    cout << "Unknown exeption happened" << endl;
                }
            }
            
        }
    }
    
    void shutdown()
    {
        {
            std::unique_lock<mutex> lk(mt);
            m_project_done = true;
        }
        m_cv.notify_all();
    }
    
protected:
    std::vector<std::thread> m_threads;
    std::queue<std::function<void()>> m_function_queue;
    bool m_project_done;
    std::mutex mt;
    std::condition_variable m_cv;
    
};

}

void threadpool7_main()
{
}

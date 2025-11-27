//
//  threadpool5.cpp
//  testcpp3
//
//  Created by hua fan on 2025-09-14.
//


#include "headers_2.h"
#include <iostream>
#include <queue>
#include <thread>
#include <functional>
#include <condition_variable>
#include <future>


using namespace std;


namespace {

class ThreadPool
{
public:
    ThreadPool (int n)
    {
        for(int i = 0; i < n; ++i)
        {
            m_threads.emplace_back(&ThreadPool::doJob, this);
        }
    }
    
    ~ThreadPool()
    {
        shutdown();
        for(auto &t : m_threads)
        {
            if(t.joinable())
                t.join();
        }
    }
    
    template<typename Func, typename... Args>
    auto enqueue(Func && func, Args && ... args)->std::future<std::invoke_result_t<Func, Args...>>
    {
        // wrap the function and its parameters into a lambda function:
        using RT = std::invoke_result_t<Func, Args...>;
        auto l1 = [f = forward<Func>(func), ...argss = forward<Args>(args)]()->RT
        {
            return std::invoke(f, argss...);
        };
        
        // wrap the lambda function into a packaged_task:
        auto task = make_shared<packaged_task<RT()>>(l1);
        auto fu = task->get_future();
        
        //wrapt the packaged task into a lambda function:
        auto l2 = [task](){ std::invoke(*task);};
        
        
        // transfer the lambda function into a std::function and
        // put the lambda function into the queue:
        {
            std::unique_lock<mutex> lk(m_mt);
            m_queue.emplace(std::function<void()>(l2));
        }
        m_cv.notify_all();
        
        return fu;
    }
    
    void shutdown()
    {
        {
            std::unique_lock<std::mutex> lk(m_mt);
            m_projectdone = true;
        }
        m_cv.notify_all();
    }
    
    void doJob()
    {
        while(true)
        {
            std::function<void()> job;
            
            {
                std::unique_lock<std::mutex> lk(m_mt);
                m_cv.wait(lk, [this](){return m_projectdone || !m_queue.empty();});
                if(m_projectdone && m_queue.empty())
                    break;
                
                if(!m_queue.empty())
                {
                    job = m_queue.front();
                    m_queue.pop();
                }
            }
            
            if(job)
            {
                try {
                    job();
                }
                catch(const exception & e)
                {
                    cout << e.what() << endl;
                }
                catch(...)
                {
                    cout << "unknown exception" << endl;
                }
            }
        }
        
    }
    
    
protected:
    std::vector<std::thread> m_threads;
    std::queue<std::function<void()>> m_queue;
    bool m_projectdone = false;
    std::mutex m_mt;
    std::condition_variable m_cv;
};

}

void threadpool5_main()
{
}



//
//  threadpool6.cpp
//  testcpp3
//
//  Created by hua fan on 2025-09-14.
//

#include "headers_2.h"
#include <iostream>
#include <thread>
#include <functional>
#include <condition_variable>
#include <future>
#include <queue>


using namespace std;

namespace
{

class ThreadPool
{
public:
    ThreadPool(int n)
    {
        for(int i = 0; i < n ; ++i)
        {
            m_threads.emplace_back(&ThreadPool::dojob, this);
        }
    }
    
    ~ThreadPool()
    {
        cout <<"Destructing pool" << endl;
        shutdown();
        for(auto &t : m_threads)
        {
            if(t.joinable())
                t.join();
        }
    }
    
    template <typename Func, typename ...Args>
    auto enqueue(Func &&func, Args&& ...args)->std::future<std::invoke_result_t<Func,Args...>>
    {
        using RT = std::invoke_result_t<Func, Args...>;
        auto l1 = [f = forward<Func>(func), ...argss = forward<Args>(args)]()->RT
        {
            return std::invoke(f, argss...);
        };
        
        auto pkg = make_shared<std::packaged_task<RT()>>(l1);
        std::future<RT> fu = pkg->get_future();
        auto l2 = [pkg](){
            std::invoke(*pkg);
        };
        
        m_queue.emplace(l2);
        return fu;
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
    void dojob()
    {
        while(true)
        {
            std::function<void()> job;
            {
                std::unique_lock<mutex> lk(m_mt);
                m_cv.wait(lk, [this]{ return m_projectdone || !m_queue.empty(); });
                
                if(m_projectdone && m_queue.empty())
                    break;
                
                if(!m_queue.empty())
                {
                    job = std::move(m_queue.front());
                    m_queue.pop();
                }
            }
            
            if(job)
            {
                try{
                    job();
                }
                catch(const exception &e)
                {
                    cout  << e.what() << endl;
                }
                catch(...)
                {
                    cout << "unknown exception" << endl;
                }
            }
        }
        
    }
    
    std::vector<std::thread> m_threads;
    std::queue<std::function<void()>> m_queue;
    bool m_projectdone = false;
    std::mutex m_mt;
    std::condition_variable m_cv;
};

//ThreadPool pool(5);

int test(int a, int b)
{
    return a + b;
}

void test2(int a, int b, int c)
{
    int d = a + b + c;
}

}

void threadpool6_main()
{
    for(int i = 0; i < 100; ++i)
    {
        //pool.enqueue(test, i, i * 2);
        //pool.enqueue(test2, i, i + 1, i + 2);
    }
}

//
//  threadpool2.cpp
//  testcpp3
//
//  Created by hua fan on 2025-09-11.
//

//
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <thread>
#include "headers_2.h"
#include <iostream>
#include <future>


using namespace std;
//

//N arrays
//E total elements
//time complexity = O(logN)*E

namespace
{
class ThreadPool
{
public:
    ThreadPool(size_t threadCount = 10) : m_projectDone(false)
    {
        for(size_t i = 0; i < threadCount; ++i)
        {
            m_threads.emplace_back(&ThreadPool::dojob, this);
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
    
    
    template<typename F, typename ...Args>
    auto enqueue(F&& func, Args...args)->std::future<typename std::invoke_result_t<F,Args...>>
    {
        using return_type = std::invoke_result_t<F,Args...>;
        auto task = make_shared<packaged_task<return_type()>>(bind(func, args...));
        std::future<return_type> res = task->get_future();
        auto lt = [task]() mutable{
            (*task)();
        };
        {
            std::unique_lock<std::mutex> lk(m_mt);
            cout << "In right value enqueue" << endl;
            m_queuejobs.push(lt);
        }
        cv.notify_one();
        return res;
    }


    void shutdown()
    {
        {
            std::unique_lock<std::mutex> lk(m_mt);
            m_projectDone = true;
        }
        cv.notify_all();
    }
    
    void create_threads()
    {
        for (int i = 0; i < 10; i ++)
        {
            m_threads[i] = std::thread(&ThreadPool::dojob, this);
        }
    }

    condition_variable cv;
    
protected:
    
    void dojob()
    {
        while(true)
        {
            std::function<void()> job;
            {
                std::unique_lock<std::mutex> lk(m_mt);
                cv.wait(lk, [this](){return m_projectDone || !m_queuejobs.empty();});
                if(m_projectDone && m_queuejobs.empty())
                {
                    break;
                }
                
                job = std::move(m_queuejobs.front());
                m_queuejobs.pop();
            }
            
            if(job)
            {
                try
                {
                    job();
                }
                catch (const std::exception &e)
                {
                    cout << e.what() << endl;
                }
                this_thread::sleep_for(2000ms);
            }
        }
    }
    bool m_projectDone;
    std::queue<std::function<void()>> m_queuejobs;
    std::vector<std::thread> m_threads;
    std::mutex m_mt;
};


std::mutex m_outmt;
ThreadPool pool(3);

}


struct func
{
    func():m_c(0){}
    
    const void operator()(int a, int b) const
    {
        int c = a + b;
    }
    int m_c;
};

int func(int a, int b)
{
    std::unique_lock<std::mutex> lk(m_outmt);
    cout << "Job : " << a << endl;
    return a+b;
}

void threadpool2_main()
{
    for(int i = 0; i <= 20; i++)
    {
        //pool.enqueue(func, i, i * 2);
    }

    pool.shutdown();
}

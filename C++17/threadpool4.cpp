//
//  threadpool4.cpp
//  testcpp3
//
//  Created by hua fan on 2025-09-13.
//


#include "headers_2.h"
#include <iostream>
#include <thread>
#include <functional>
#include <future>
#include <vector>
#include <queue>


using namespace std;
using namespace std::chrono_literals;


namespace
{

class ThreadPool
{
public:
    ThreadPool(int n)
    {
        for(int i = 0; i < n; i++)
            m_threads.emplace_back(&ThreadPool::doJob, this);
    }
    
    ~ThreadPool()
    {
        shutdown();
        for(auto &t : m_threads)
        {
            if(t.joinable())
            {
                t.join();
            }
        }
    }
    
    template <typename Func, typename... Args>
    auto enqueue(Func&& func, Args&& ... args)->std::shared_future<std::invoke_result_t<Func, Args...>>
    {
        using RT = std::invoke_result_t<Func, Args...>;
        auto l = [f = forward<Func>(func), ...args = forward<Args>(args)]()->RT
        {
            return std::invoke(f, args...);
        };
        
        auto pkg = std::make_shared<packaged_task<RT()>>(l);
        
        std::shared_future<RT> fu = pkg->get_future().share();
        
        auto l2 = [pkg](){ std::invoke(*pkg);};
        
        {
            std::unique_lock<std::mutex> lk(m_mt);
            m_queue.push(l2);
        }
        
        m_cv.notify_one();
        
        return fu ;
    }
    
    void doJob()
    {
        while(true)
        {
            std::function<void()> job;
            {
                std::unique_lock<std::mutex> lk(m_mt);
                m_cv.wait(lk, [this]{ return m_projectDone || !m_queue.empty();});
                if(m_projectDone && m_queue.empty())
                {
                    break;
                }
                
                if(!m_queue.empty())
                {
                    job = std::move(m_queue.front());
                    m_queue.pop();
                }
            }
            
            if(job)
            {
                try {
                    job();
                }
                catch (const exception &e)
                {
                    cout << e.what() << endl;
                }
                catch(...)
                {
                    cout << "Unknow exception " << endl;
                }
            }
        }
    }
    
    void shutdown()
    {
        {
            std::unique_lock<std::mutex> lk(m_mt);
            m_projectDone = true;
        }
        m_cv.notify_all();
    }
    
protected:
    vector<std::thread> m_threads;
    std::queue<std::function<void()>> m_queue;
    bool m_projectDone = false;
    std::mutex m_mt;
    std::condition_variable m_cv;
};

ThreadPool pool(5);

int add(int a, int b)
{
    this_thread::sleep_for(1000ms);
    return a + b;
}

}

void threadpool4_main()
{
    std::vector<shared_future<int>> res;
    for(int i = 0 ; i < 100; i ++)
    {
        res.push_back(pool.enqueue(add, i ,i));
    }
    
    std::promise<int> p;
    std::future<int> f1 = p.get_future();
    shared_future<int> f = f1.share();

    
    while(!res.empty())
    {
        res.erase(
            std::remove_if(res.begin(), res.end(),
                [](auto &f){
                    if(f.wait_for(0ms) == std::future_status::ready)
                    {
                        cout << f.get() << endl;
                        return true;
                    }
                    return false;
                }),
            res.end()
        );

        std::this_thread::sleep_for(1ms);
    }
    
    
}

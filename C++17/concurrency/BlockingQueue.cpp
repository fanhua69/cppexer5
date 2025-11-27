//
//  BlockingQueue.cpp
//  testcpp3
//
//  Created by hua fan on 2025-09-15.
//


#include "headers_2.h"
#include <iostream>
#include <queue>
#include <functional>
#include <mutex>
#include <thread>


using namespace std;

namespace {

template <typename T>
class BlockingQueue
{
public:
    BlockingQueue(int n) : m_ability(n) {}
    
    void put(const T& data)
    {
        {
            std::unique_lock<mutex> lk(m_mt);
            m_has_capacity.wait(lk, [this](){ return m_queue.size() < m_ability; });
            m_queue.push(data);
        }
        m_has_value.notify_one();
    }
    
    T take()
    {
        T data;
        {
            std::unique_lock<mutex> lk(m_mt);
            m_has_value.wait(lk, [this](){ return m_productionDone == true ||  m_queue.size() > 0;});
            if(m_queue.size () == 0 && m_productionDone )
            {
                return -1;
            }
            
            data = m_queue.front();
            m_queue.pop();
        }
        m_has_capacity.notify_one();
        
        return data;
    }
    
  
    void shutdown()
    {
        {
            unique_lock<mutex> lk(m_donemt);
            m_productionDone = true;
        }
        m_has_capacity.notify_all();
        m_has_value.notify_all();
    }

protected:
    queue<T> m_queue;
    std::mutex m_donemt;
    std::mutex m_mt;
    std::condition_variable m_has_value;
    std::condition_variable m_has_capacity;

    int m_ability = 10;
    bool m_productionDone = false;
};

BlockingQueue<int> bq(10);
std::mutex m_coutmt;

std::atomic<int> m_doneJob = 0;
std::mutex m_doneJobMutex;




void producer()
{
    for(int i = 0; i < 10; ++i)
    {
        bq.put(i);
        {
            std::unique_lock<mutex> lk(m_coutmt);
            cout << "Producing:" << i << endl;
        }

        this_thread::sleep_for(500ms);
    }
    m_doneJob++;
}

void consumer()
{
    while(true)
    {
        int n = bq.take();
        if(n==-1)
        {
            break;
        }
        
        {
            std::unique_lock<mutex> lk(m_coutmt);
            cout << "Consuming: " << n << endl;
        }
    }
}


}

void BlockingQueue_main()
{
    vector<thread> ps;
    for(int i = 0; i < 10; ++i)
    {
        ps.emplace_back(producer);
    }
    
    
    for(int i = 0 ; i < 4; ++i)
    {
        ps.emplace_back(consumer);
    }
    
    while(true)
    {
        std::unique_lock<std::mutex> lk(m_doneJobMutex);
    }
    
    for(auto &t : ps)
        t.join();
}

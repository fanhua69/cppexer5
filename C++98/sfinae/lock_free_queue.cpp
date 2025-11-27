//
//  lock_free_queue.cpp
//  testcpp3
//
//  Created by hua fan on 2025-10-24.
//

#include <deque>
#include <vector>
#include <atomic>
#include <optional>
#include <thread>

using namespace std;

namespace
{

template <typename T>
class LockFreeQueue
{
public:
    LockFreeQueue(int n) : m_capacity (n), m_queue(n,0), m_head(0), m_tail(0)
    {
        
    }
    
    bool enqueue(T&& t)
    {
        int tail = m_tail.load(std::memory_order_relaxed);
        while(true)
        {
            int head = m_head.load(std::memory_order_relaxed);
            if((tail + 1) & (m_capacity - 1 )== head % m_capacity)
                return false;
            
            if(m_tail.compare_exchange_weak(tail, tail+1,std::memory_order_acq_rel, std::memory_order_relaxed))
            {
                int p = tail & (m_capacity -1 );
                m_queue[p] = std::move(t);
                return true;
            }
            
            std::this_thread::yield();
        }
    }
    
    std::optional<T> pop()
    {
        int head = m_head.load(std::memory_order_relaxed);
        while(true)
        {
            int tail = m_tail.load(std::memory_order_relaxed);
            if(tail <= head)
                return {};
            
            if(m_head.compare_exchange_weak(head, head+1, std::memory_order_acq_rel))
            {
                int p = head &( m_capacity -1 );
                return std::move(m_queue[p]);
            }
            std::this_thread::yield();
        }
    }
    
    size_t size() const
    {
        int head = m_head.load(std::memory_order_relaxed);
        int tail = m_tail.load(std::memory_order_relaxed);
        return (tail - head + m_capacity) & (m_capacity - 1);
    }
    
    
protected:
    std::vector<T> m_queue;
    atomic<int> m_head;
    atomic<int> m_tail;
    int m_capacity;
};

}

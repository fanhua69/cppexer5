//
//  lock_free_queue.cpp
//  testcpp3
//
//  Created by hua fan on 2025-10-20.
//


#include "headers_2.h"
#include <iostream>
using namespace std;

#include <atomic>

template<typename T>
class lock_free_queue
{
public:
    lock_free_queue(int capacity):
    m_capacity(capacity),
    m_buffer(capacity),
    m_head(0),
    m_tail(0)
    {
    }
    
    bool enqueue(T d)
    {
        size_t tail = m_tail.load(std::memory_order_relaxed);
        while(true)
        {
            size_t head = m_head.load(std::memory_order_acquire);
            if(tail - head >= m_capacity)
            {
                return false;
            }
            
            if(m_tail.compare_exchange_weak(tail, tail+1,std::memory_order_acq_rel))
            {
                m_buffer[tail % m_capacity] = d;
                return true;
            }
        }
        
        
    }
    
protected:
    int m_capacity;
    std::vector<T> m_buffer;
    std::atomic<int> m_head;
    std::atomic<int> m_tail;
};

void lock_free_queue_main()
{
}

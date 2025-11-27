//
//  ring_buffer.cpp
//  testcpp3
//
//  Created by hua fan on 2025-10-24.
//

#include <vector>
#include <optional>

using namespace std;

namespace
{
template <typename T>
class RingBuffer
{
public:
    RingBuffer(int n) : m_capacity (n), m_vector(n), m_head(0), m_tail(0)
    {
    }
    
    void pushdata(T d)
    {
        if(m_tail - m_head >= m_capacity)
            return;
        
        int p = m_tail % m_capacity;
        m_vector[p] = d;
        m_tail++;
    }
    
    std::optional<T> popdata()
    {
        if(m_tail == m_head)
            return {};
        
        int p = m_head % m_capacity;
        T d = m_vector[p];
        m_head++;
        return d;
    }
    
    
protected:
    
    int m_head;
    int m_tail;
    vector<T> m_vector;
    int m_capacity;
};

}

#include "headers_2.h"
#include <iostream>
using namespace std;

void ring_buffer_main()
{
}

//
//  heap1.cpp
//  testcpp3
//
//  Created by hua fan on 2024-11-30.
//


#include <vector>
#include <iostream>
#include "print.h"

using namespace std;

class heap
{
    public:
        void heapify(int p)
        {
            int N = m_data.size();

            int lc = p * 2 + 1;
            int lr = lc + 1;

            int lp = p;

            if(lc < N && m_data[p] > m_data[lc])
            {
                p = lc;
            }

            if (lr < N && m_data[p] > m_data[lr])
            {
                p = lr;
            }

            if(lp != p)
            {
                swap(m_data[lp], m_data[p]);
                heapify(p);
            }
        }

        void add(int d)
        {
            m_data.push_back(d);

            //
            int index=m_data.size() - 1;
            while(index > 0)
            {
                int p = (index - 1) / 2;

                if(m_data[index] < m_data[p])
                {
                    swap(m_data[index], m_data[p]);
                    index = p;
                }
                else
                {
                    break;
                }
            }
        }

        void pop()
        {
            if(m_data.size() == 0)
                return;

            m_data[0] = m_data[m_data.size() - 1];
            m_data.pop_back();
            heapify(0);
        }

        int peek()
        {
            if(m_data.size() == 0)
                return -1;

            return m_data[0];
        }

    public:
        vector<int> m_data;
};



void heap_1_main()
{
    heap h;

    for(int i = 100; i >= 0 ; i --)
        h.m_data.push_back(i);

    h.heapify(0);

    print(h.m_data);

    while(h.m_data.size())
    {
        int d = h.peek(); h.pop();
        print(d);
    }

}

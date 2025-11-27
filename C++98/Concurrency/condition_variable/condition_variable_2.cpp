//
//  condition_variable_2.cpp
//  testcpp3
//
//  Created by hua fan on 2023-12-31.
//

#include <stdio.h>

#include "headers.h"
#include <mutex>
#include <condition_variable>

namespace condition_variable_2
{
    static std::stack<int> g_data;
    static std::mutex g_mutex;
    static std::condition_variable condFeed;
    static std::condition_variable condCons;


    void feed()
    {
        int count = 0;
        while(count < 100)
        {
            std::unique_lock<std::mutex> locker(g_mutex);
            while(g_data.size() > 0 )
            {
                condFeed.wait(locker);
            }

            for(int i = 0; i< 3; i++)
            {
                g_data.push(count);
                cout << "Feed : " << count << endl;
                count ++;
            }

            condCons.notify_all();
        }
    }

    void consume()
    {
        int data = -1;
        while(data < 100)
        {
            std::unique_lock<std::mutex> locker;
            while(g_data.size() < 3)
            {
                condCons.wait(locker);
            }

            while(g_data.size())
            {
                data = g_data.top();
                cout << "Got : " << data << endl;
                g_data.pop();
            }

            condFeed.notify_all();
        }
    }

}

#include "headers_2.h"
#include <iostream>
using namespace std;

void condition_variable_2_main()
{
}

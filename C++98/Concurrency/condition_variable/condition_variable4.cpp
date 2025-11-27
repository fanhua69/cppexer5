//
//  condition_variable4.cpp
//  testcpp3
//
//  Created by hua fan on 2025-09-08.
//

#include "headers_2.h"
#include <iostream>
#include <shared_mutex>
#include <condition_variable>
#include <thread>
#include <chrono>

using namespace std;
using namespace std::chrono_literals;

namespace condition_variable4
{

    int data = 0;
    mutex mu;
    std::condition_variable_any cv;
    bool data_ready_write = false;
    int  data_read_by = 0;
    bool data_ready_read  = true;

    void producer()
    {
        while(true)
        {
            std::unique_lock<mutex> lk(mu);
            cv.wait(lk, [](){ return data_ready_write; });
            data++;
            data_ready_write = false;
            data_ready_read = true;
            data_read_by = 0;

            cv.notify_all();
            this_thread::sleep_for(100ms);
        }
    }

    void consumer()
    {
        while(true)
        {
            std::unique_lock<mutex> lk(mu);
            cv.wait(lk, [](){return data_ready_read;});
            cout << data_read_by << " : " <<  data << endl;

            data_read_by++;
            if(data_read_by>=5)
            {
                data_ready_read = false;
                data_ready_write = true;
            }
            
            cv.notify_all();
            this_thread::sleep_for(100ms);
        }
    }
}

void condition_variable4_main()
{
    std::thread tw(condition_variable4::producer);
    std::thread tr[5];
    for(int i = 0; i < 5; i++)
        tr[i] = std::thread(condition_variable4::consumer);
    
    tw.join();
    for(int i = 0; i < 5; i++)
        tr[i].join();
    
}

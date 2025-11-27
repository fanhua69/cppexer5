//
//  condition_variable_any_1.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-27.
//

#include <stdio.h>
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>


std::mutex mtx;
std::condition_variable_any cv;

int ready = 0;

void worker_thread()
{
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [](){return ready;});

    std::cout << "Worker thread is processing data. \n";
}

void condition_variable_any_1_main()
{
    std::thread worker(worker_thread);

    std::cout << " Main thread is doing some work\n";
    for(int i = 0; i < 5; i ++)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << " waiting ... " << std::endl;
    }

    cv.notify_one();

    std::cout << " noted once  ... " << std::endl;
    cv.notify_one();

    std::cout << " noted once  ... " << std::endl;


    {
        //std::lock_guard<std::mutex> lock(mtx);
        ready = true;
    }

    std::cout << " noted twice  ... " << std::endl;

    cv.notify_one();
        std::cout << " noted twice done ... " << std::endl;

    worker.join();
        std::cout << " work done  ... " << std::endl;
}

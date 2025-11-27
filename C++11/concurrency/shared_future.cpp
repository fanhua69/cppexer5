//
//  shared_future.cpp
//  testcpp3
//
//  Created by hua fan on 2025-11-06.
//


#include "headers_2.h"
#include <iostream>
#include <future>
#include <chrono>
#include <thread>


using namespace std;

void shared_future_main()
{
    std::shared_future<int> f = std::async([](){std::this_thread::sleep_for(1s); return 10;});
//    std::shared_future<int> fs = f.share();
    f.get();
    f.get();
    
    auto ff = f;
    
    
}

//
//  future2.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-28.
//

#include <stdio.h>
#include <future>
#include <thread>
#include <chrono>
#include <iostream>

int calc()
{
    std::this_thread::sleep_for(std::chrono::seconds(3));
    return 1;
}


void future2_main()
{
    std::future<int> f = std::async(calc);
    std::cout << f.get() << std::endl;
}

//
//  async1.cpp
//  testcpp3
//
//  Created by hua fan on 2025-07-23.
//

#include "headers_2.h"
#include <iostream>
#include <thread>
#include <future>

using namespace std;
 
int testasync(int a)
{
    print("Thread id in the async function:");
    print(std::this_thread::get_id());
    cout << "getting into testasync" << endl;
    std::this_thread::sleep_for(2110ms);
    cout << "slept int testasync" << endl;
    
    return a * 10;
}


void async1_main()
{
    print("Thread id in the Main function:");
    print(std::this_thread::get_id());

    std::future<int> f = std::async(std::launch::deferred, testasync, 10);
    
    
    cout << "after calling async" << endl;
    f.wait();
    
    int n = f.get();
    cout << "after f.get: " << n << endl;
}

//
//  future_1.cpp
//  testcpp3
//
//  Created by hua fan on 2024-02-05.
//



#include <thread>
#include <iostream>
#include <future>

using namespace std;

int threadF11()
{
    int n = 0;
    cin >> n ;
    return n;
}

void threadF2(std::future<int> f)
{
    int d = f.get();
    cout << "In thread 2 Result:" << d << endl;
}


void future_1_main()
{
    std::future<int> f2 = std::async(launch::async, threadF11);
    std::thread t3(threadF2, std::move(f2));
    t3.join();
}


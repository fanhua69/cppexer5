//
//  conditional_variable_3.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-28.
//

#include <stdio.h>
#include <condition_variable>
#include <chrono>
#include <thread>
#include <iostream>

using namespace std;

std::condition_variable cond3;
std::mutex mutex_cond;

void cond_thread1()
{
    cout << "Sleeping thread 1 ...." <<endl;
    std::this_thread::sleep_for(chrono::seconds(3));
    cout << "Sleeping Done thread 1 ...." << endl;
    cond3.notify_one();
    cout << "Tread 1 notified all 1...." << endl;
    std::this_thread::sleep_for(chrono::seconds(3));
    cout << "Sleeping Done thread 2 ...." << endl;
    cond3.notify_one();
    cout << "Tread 1 notified all. 2..." << endl;
    std::this_thread::sleep_for(chrono::seconds(3));
    cout << "Sleeping Done thread 2 ...." << endl;
    cond3.notify_all();
    cout << "Tread 1 notified all. 3..." << endl;

}

void cond_thread2()
{
    cout << " Thread 2 waiting" << endl;
    std::unique_lock<std::mutex> lock(mutex_cond);
    cond3.wait(lock);
    cout << "Thread 2 got notification  1 " << endl;
    cond3.wait(lock);
    cout << "Thread 2 got notification  2 " << endl;
    cond3.wait(lock);
    cout << "Thread 2 got notification  3 " << endl;
}

void cond_thread3()
{
    cout << " Thread 3 waiting" << endl;
    std::unique_lock<std::mutex> lock(mutex_cond);
    cond3.wait(lock);
    cout << "Thread 3 got notification  1 " << endl;
    cond3.wait(lock);
    cout << "Thread 3 got notification  2 " << endl;
    cond3.wait(lock);
    cout << "Thread 3 got notification  3 " << endl;
}


void cond3_main()
{
    std::thread t1(cond_thread1);
    std::thread t2(cond_thread2);
    std::thread t3(cond_thread3);

    t1.join();
    t2.join();
    t3.join();


}

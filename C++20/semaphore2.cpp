//
//  semaphore2.cpp
//  testcpp3
//
//  Created by hua fan on 2025-10-02.
//


#include "headers_2.h"
#include <iostream>
#include <semaphore>
#include <thread>
//#include <chrono>

using namespace std;


#include <iostream>
#include <semaphore>
#include <thread>
#include <vector>
using namespace std;

namespace {

std::counting_semaphore<5> sem(3);

void worker(int id) {
    sem.acquire();
    cout << "Thread " << id << " acquired\n";
    this_thread::sleep_for(1s);
    sem.release();
}


class ttt
{
public:
    inline static int n = 0;
};

 // int ttt:n = 1; cause redefinition


}


void semaphore2_main()
{
    try {
        sem.release(10); // 超过 N
        
        sem.release();
        sem.release();
        sem.release();
        sem.release();
        sem.release();
        cout << "release(10) done\n";
    } catch (...) {
        cout << "Exception!\n";
    }

    
    vector<thread> ts;
    for (int i = 0; i < 10; i++) { // 10 线程抢 5 个资源
        ts.emplace_back(worker, i);
    }
    for (auto& t : ts) t.join();

}

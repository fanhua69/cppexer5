//
//  semophore1.cpp
//  testcpp3
//
//  Created by hua fan on 2025-09-08.
//



#include "headers_2.h"
#include <iostream>
#include <thread>
#include <semaphore>

using namespace std;


namespace {

std::counting_semaphore<3> sem(3);
int printer = 13;
std::mutex mu;

void user(int i)
{
    while(true)
    {
        sem.acquire();
        {
            std::unique_lock<mutex> lk(mu);
            if(printer > 0)
                printer --;
            cout << "Using Printer, now free printers: " << printer << ", thread : " << i << endl;
        }
        
        this_thread::sleep_for(std::chrono::milliseconds(1000));
        {
            std::unique_lock<mutex> lk(mu);
            printer++;
        }
        
        sem.release();
    }
}

}
    
void semophore1_main()
{
    std::vector<thread> vt(3);
    for(int i = 0; i < 3; i ++)
        vt[i] = thread(user, i);
    
    for(int i = 0; i < 3; i++)
        vt[i].join();
        
}

//
//  timeQueue.cpp
//  testcpp3
//
//  Created by hua fan on 2024-05-04.
//

#include <stdio.h>
#include <chrono>
#include <list>
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
using namespace std::chrono;


struct Data
{
    int d;
    std::chrono::time_point<std::chrono::steady_clock> t;

    Data(int dt, time_point<steady_clock> tt)
    {
        d = dt;
        t = tt;
    }
};

std::mutex g_mutexData;


std::list <Data> g_list;
int g_duration;

void enqueue(int d)
{
    std::lock_guard<mutex> g(g_mutexData);
    g_list.emplace_back(d, steady_clock::now());
}

void printList()
{
    for ( auto [a,b ] : g_list)
    {
        cout << a << ", " << b.time_since_epoch().count() << endl;
    }
}

void printList2()
{
    std::list<Data>::iterator it = g_list.begin();
    while(it != g_list.end())
    {
        cout << it->d << ", " << it->t.time_since_epoch().count() << endl;
        it++;
    }
}

void deleteData()
{
    std::unique_lock<mutex> lock(g_mutexData);

    auto n = steady_clock::now();
    while(g_list.size())
    {
        auto h = g_list.front();
        int ss = duration_cast<seconds>(n - h.t).count();
        if( ss > g_duration)
        {
            cout << "Deleting:" <<  h.d << ", Seconds:" << ss << endl;
            g_list.pop_front();

        }
        else
        {
            break;
        }
    }
}

void inData()
{
    while(true)
    {
        int n;
        cin >> n;
        if(n == -1 || n == 0)
        {
            break;
        }
        enqueue(n);
    }
}

void DeleteDataThread()
{
    while(true)
    {
        std::this_thread::sleep_for(seconds(1));
        deleteData();
    }
}

void time_queue_main()
{
    g_duration = 5;
    std::thread t1(inData);
    std::thread t2(DeleteDataThread);
    t1.join();
    t2.join();
}

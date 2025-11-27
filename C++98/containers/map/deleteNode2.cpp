//
//  deleteNode2.cpp
//  testcpp3
//
//  Created by hua fan on 2024-05-04.
//

#include <stdio.h>
#include <iostream>
#include <map>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;
using namespace chrono;

std::mutex g_coutm;
std::mutex g_mapm;
std::map<steady_clock::time_point, int> g_map;

void addNode()
{
    while(true)
    {
        int value, duration;
        {
            std::unique_lock<std::mutex> g(g_coutm);
            cout << "Add a node, value:";
            cin >> value;
            cout << endl;
            cout << "Add a node, duration:";
            cin >> duration;
            cout << endl;
        }

        auto t = steady_clock::now();
        auto t2 = t + seconds(duration);

        {
            std::lock_guard<std::mutex> lg(g_mapm);
            g_map.emplace(t2, value);
        }
        this_thread::sleep_for(1s);
    }
}

void deleteNode()
{
    while(true)
    {
        this_thread::sleep_for(10ms);
        std::unique_lock<mutex> lg(g_mapm);
        if(g_map.size())
        {
            auto tn = steady_clock::now();
            auto it = g_map.begin();
            while(it!=g_map.end())
            {
                if (tn < it->first)
                {
                    break;
                }
                it = g_map.erase(it);
            }
        }
        lg.unlock();
    }
}

void deleteNode2_main()
{
    std::thread t1(addNode);
    std::thread t2(deleteNode);
    t1.join();
    t2.join();
}

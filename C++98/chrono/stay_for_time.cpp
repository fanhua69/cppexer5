//
//  stay_for_time.cpp
//  testcpp3
//
//  Created by hua fan on 2024-12-12.
//

#include <iostream>
#include <map>
#include <mutex>
#include <thread>
#include <chrono>


using namespace std;

static map<chrono::time_point<chrono::steady_clock>, string> time_data;

std::mutex mt_cout;
std::mutex mt_data;
std::atomic<bool> a_data = false;
std::atomic<bool> a_cout = false;

void getData()
{
    while(true)
    {
        int stay_seconds;
        string info;

        {
            while(a_cout.load() == true)
            {
                this_thread::sleep_for(100ms);
            }
            a_cout.store(true);
            cout << "Stay Seconds:";
            cin >> stay_seconds;
            cout << endl;

            cout << "Data:";
            cin >> info;
            cout << endl;
            a_cout.store(false);
        }

        {
            chrono::time_point ct = chrono::steady_clock::now();
            chrono::seconds ds(stay_seconds);
            chrono::time_point tp = ct + ds;
            std::unique_lock<std::mutex> ul(mt_data);
            time_data[tp] = info;
            ul.unlock();
        }

        std::this_thread::sleep_for(500ms);
    }
}

void deleteDurationData()
{
    while(true)
    {
        std::unique_lock<std::mutex> lk(mt_data);
        std::chrono::time_point ct = std::chrono::steady_clock::now();
   
        auto it = time_data.begin();
        while(it != time_data.end())
        {
            if(ct > it->first)
            {
                while(a_cout.load() == false)
                {
                    this_thread::sleep_for(100ms);
                }
                a_cout.store(true);
                cout << "Deleted:" << it->second << endl;
                a_cout.store(false);

                it = time_data.erase(it);
            }
            else
            {
                ++it;
            }
        }
        lk.unlock();

        std::this_thread::sleep_for(500ms);
    }
}


void stay_for_time_main()
{
    std::thread tin(getData);
    std::thread tout(deleteDurationData);

    tin.join();
    tout.join();
}


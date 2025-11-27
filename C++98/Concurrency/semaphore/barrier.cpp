//
//  barrier.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-04.
//

#include <stdio.h>
#include <iostream>
#include <barrier>
#include <mutex>
#include <string>
#include <thread>
#include <chrono>

static std::barrier workDone(4);
static std::mutex coutMutex;

static void syncOut(const std::string& s) noexcept
{
    std::lock_guard<std::mutex> lo(coutMutex);
    std::cout << s ;
}

class FullTimeWorker
{
    public:
        FullTimeWorker(std::string n, int worktime_) : name(n), worktime(worktime_) {};

        void doMorningWork()
        {
            syncOut(name + " doing morning work\n");
            std::this_thread::sleep_for(std::chrono::seconds(worktime));
            syncOut(name + ": " + " Morning word done!\n");
        }

        void doAfternoonWork()
        {
            syncOut(name + " doing afternoon work\n");
            std::this_thread::sleep_for(std::chrono::seconds(worktime));
            syncOut(name + ": " + " Afternoond work done!\n");
        }

        void doNightWork()
        {
            syncOut(name + " doing night work\n");
            std::this_thread::sleep_for(std::chrono::seconds(worktime));
            syncOut(name + ": " + " Night work done!\n");
        }
        

        void operator () ()
        {
            doMorningWork();
            std::barrier<>::arrival_token&& t = workDone.arrive();
            workDone.wait(std::move(t));

            doAfternoonWork();
            workDone.arrive_and_wait();  // Wait until afternoon work is donw=e

            doNightWork();
            workDone.arrive_and_wait();  // Wait until afternoon work is donw=e
        }

    private:
        std::string name;
        int worktime;
};

void barrier_main()
{
    FullTimeWorker w1("david ", 5);
    std::thread t1(w1);

    FullTimeWorker w2("smith ", 4);
    std::thread t2(w2);

    FullTimeWorker w3("Tedd ", 2);
    std::thread t3(w3);

    FullTimeWorker w4("Ming ", 1);
    std::thread t4(w4);

    t1.join();
    t2.join();
    t3.join();
    t4.join();



}








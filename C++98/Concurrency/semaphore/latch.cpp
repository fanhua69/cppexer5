//
//  latch.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-04.
//

#include <stdio.h>
#include <latch>
#include "headers.h"
#include <mutex>
#include <thread>

std::latch workDone(4);
std::latch goHome(1);


void synchronizeOut(const std::string s)
{
    std::mutex coutMutex;
    std::lock_guard<std::mutex> locker(coutMutex);
    std::cout << s ;
}

class Worker
{
    public:
        Worker(std::string n) : name(n) {};

        void operator () ()
        {
            synchronizeOut(name+":" + " Work done\n");
            workDone.count_down();

            goHome.wait();
            synchronizeOut(name + " : " + "good bye\n");
        }
    private:
        std::string name;
};

class NNN
{};

void latch_main()
{
    cout << sizeof(NNN) << endl;

    cout << endl;
    cout << "Boss: Start working" << endl;

    Worker herb(" herb");
    std::thread herbWork(herb);

    Worker bjarne(" Bjarne");
    std::thread bjarneWork(bjarne);

    Worker david(" david");
    std::thread davidWork(david);

    Worker smith(" Smith");
    std::thread smithWork(smith);

    workDone.wait();
    cout << endl;

    cout << "BOSS: go home" << endl;
    goHome.count_down();

    herbWork.join();
    bjarneWork.join();
    davidWork.join();
    smithWork.join();
}

//
//  firstsecondthird2.cpp
//  testcpp3
//
//  Created by hua fan on 2024-12-13.
//

#include <condition_variable>
#include <iostream>
#include <thread>

using namespace std;

std::mutex g_mt;
std::condition_variable cv_third;
int order3 = 0;


class FooSecond
{
public:
    FooSecond()
    {}

    void printFirst()
    {
        std::unique_lock<std::mutex> lk(g_mt);

        cout << "first" << endl;
        order3++;
        cv_third.notify_all();
    }

    void printSecond()
    {
        std::unique_lock<std::mutex> lk(g_mt);
        while(order3 != 1)
        {
            cv_third.wait(lk, [&](){return order3 == 1;});
        }
        cout << "second" << endl;

        order3++;
        cv_third.notify_all();
    }

    void printThird()
    {
        std::unique_lock<std::mutex> lk(g_mt);
        while(order3 != 2)
        {
            cv_third.wait(lk, [&](){return order3 == 2;});
        }

        cout << "third" << endl;

        order3++;
        cv_third.notify_all();
    }
};

void firstSecondThird_2_main()
{
    FooSecond f;
    std::thread t1(&FooSecond::printThird, std::ref(f));
    std::thread t2(&FooSecond::printSecond, std::ref(f));
    std::thread t3(&FooSecond::printFirst, std::ref(f));

    t1.join();
    t2.join();
    t3.join();

}

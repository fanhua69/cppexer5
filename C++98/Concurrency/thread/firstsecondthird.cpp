//
//  firstsecondthird.cpp
//  testcpp3
//
//  Created by hua fan on 2024-12-13.
//

#include <functional>
#include <utility>
#include <iostream>
#include <atomic>
#include <condition_variable>
#include <thread>

using namespace std;


std::condition_variable cv_first;
std::mutex mt;



class Foo {
public:
    int order = 0;

    Foo() 
    {
         
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        order++;
        cv_first.notify_all();
    }

    void second(function<void()> printSecond) {

        std::unique_lock<std::mutex> lock(mt);
        while(order != 1)
        {
            cv_first.wait(lock, [&](){return order == 1 ;});
        }

        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        order ++;
        cv_first.notify_all();
    }

    void third(function<void()> printThird) {
        std::unique_lock<std::mutex> lock(mt);
        while(order!=2)
        {
            cv_first.wait(lock, [&](){return order == 2;});
        }

        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        order++;
        cv_first.notify_all();
    }
};

void printFirst()
{
    cout << "first" <<endl;
}

void printSecond()
{
    cout << "second" <<endl;
}

void printThird()
{
    cout << "Third" <<endl;
}

void function_main()
{
    Foo f;
    std::thread t1(&Foo::second, std::ref(f), printSecond);
    std::thread t2(&Foo::first, std::ref(f), printFirst);
    std::thread t3(&Foo::third, std::ref(f), printThird);
    t1.join();
    t2.join();
    t3.join();
}

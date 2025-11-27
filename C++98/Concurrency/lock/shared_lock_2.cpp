//
//  shared_lock_2.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-01.
//

#include <stdio.h>
#include <iostream>
#include <shared_mutex>
#include <thread>
#include <mutex>

std::mutex mutex_cout;

class ThreadSafeCounter
{
    public:
        ThreadSafeCounter() = default;

        unsigned int get() const
        {
            std::shared_lock lock(mutex_);
            return value_;
        }

        void increment()
        {
            std::unique_lock lock(mutex_);
            ++value_;
        }

        void reset()
        {
            std::unique_lock lock(mutex_);
            value_=0;
        }

    private:
        mutable std::shared_mutex mutex_;
        unsigned int value_ = 0;
};

void shared_lock_main1()
{
    ThreadSafeCounter counter;
    std::cout << "original value: " << counter.get() << std::endl;
    auto increment_and_print = [&counter](){
        for (int i = 0; i < 100 ; i++)
        {
            std::lock_guard lock(mutex_cout);
            counter.increment();
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            std::chrono::time_point t1 = std::chrono::system_clock::now();

            std::cout << std::this_thread::get_id() << ' ' << counter.get() << '\n';
        }
    };

    std::thread thread1(increment_and_print);
    std::thread thread2(increment_and_print);
    std::thread thread3(increment_and_print);

    thread1.join();
    thread2.join();
    thread3.join();

}

//
//  promise.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-08.
//

#include <stdio.h>
#include <future>
#include "headers.h"
#include <chrono>
#include <numeric>
#include <vector>
#include <thread>


void Accumulate(std::vector<int>::iterator first,
                std::vector<int>::iterator last,
                std::promise<int> accumulate_promise)
{
    int sum = std::accumulate(first, last, 0);
    accumulate_promise.set_value(sum);
}

// thread 1 set the value of the promise:
void do_work1(std::promise<int> &barrier)
{
    std::this_thread::sleep_for(std::chrono::seconds(3));
    int iVal = 233;
    cout << "in coming data : " << iVal << endl;
    barrier.set_value(iVal);
}

void do_work2(std::future<int> &fun)
{
    auto iVal = fun.get();
    cout << "got data : " << iVal << endl;
}


void promise_main()
{
    // show how to send result among threads:
    vector<int> numbers = {1,2,3,4};
    std::promise<int> accumulate_promise;
    std::future<int> accumulate_future = accumulate_promise.get_future();
    std::thread work_thread(Accumulate, numbers.begin(), numbers.end(), std::move(accumulate_promise));
    cout << "Result " << accumulate_future.get() << endl;
    work_thread.join();

    // Show how to send state among threads:
    std::promise<int> barrier_promise;
    std::future<int> barrier_future = barrier_promise.get_future();
    std::thread new_work1_thread(do_work1, std::ref(barrier_promise));
    std::thread new_work2_thread(do_work2, std::ref(barrier_future));

    new_work1_thread.join();
    new_work2_thread.join();
}

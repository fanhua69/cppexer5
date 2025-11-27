//
//  future.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-08.
//

#include <stdio.h>

#include <future>
#include <chrono>
#include "headers.h"
#include <thread>

bool is_prime(int x)
{
    std::this_thread::sleep_for(milliseconds(5000));

    for (int i = 2; i < x ; ++i)
    {
        if( 0 == x % i)
            return false;
    }

    return true;
}


void future_main()
{
    std::future<bool> fut = std::async(std::launch::async, is_prime, 444444443);

    std::future_status status = fut.wait_for(std::chrono::milliseconds(10));

    // check status , modify wait for time would get different status:
    if(status == std::future_status::deferred)
    {
        std::cout << "1111 defered not started\n";
    }
    else if(status == std::future_status::timeout)
    {
        cout << "1111 time out\n";
    }
    else if (status == std::future_status::ready)
    {
        cout << "1111 done\n";
    }

    // do somthing while waiting:
    cout << "checking , please wait";
    std::chrono::milliseconds span(10);


    while(fut.wait_for(span) == std::future_status::timeout)
    {
        cout << "." << std::flush;;
    }
     cout << endl;


    status = fut.wait_for(std::chrono::milliseconds(1));

    if(status == std::future_status::deferred)
    {
        std::cout << "2222 d2efered not started\n";
    }
    else if(status == std::future_status::timeout)
    {
        cout << "2222 time out\n";
    }
    else if (status == std::future_status::ready)
    {
        cout << "2222 done\n";
    }

   // std::shared_future<bool> share_fut = fut.share();

    bool x = false;

    if(fut.valid())
    {
        x = fut.get();
        cout << "fut is valid, use its data." << endl;
    }
    else
    {
     //   x = share_fut.get();
        cout << "fut is not valid, use its transfer share data" << endl;
    }

    cout << "\n444444443 " << (x ? "is " : "is not ") << " prime .\n";


}

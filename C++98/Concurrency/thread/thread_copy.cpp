//
//  thread_copy.cpp
//  testcpp3
//
//  Created by hua fan on 2024-02-05.
//

#include <stdio.h>
#include <thread>
#include "headers.h"

namespace concurrency
{


void thread_copy_main()
{
    std::thread th;
    th = std::thread([](){cout << "in thread " << endl; return 1;});

    std::thread th2 = std::move(th);

    th2.join();
}

}

//
//  duration2.cpp
//  testcpp2
//
//  Created by hua fan on 2023-08-22.
//

#include <stdio.h>
#include "headers.h"
#include <chrono>
#include <thread>

using namespace std::chrono;


void duration2Main()
{
    time_point<high_resolution_clock> t1 = high_resolution_clock::now();
    this_thread::sleep_for(milliseconds{2000});
    time_point<steady_clock> t2 = steady_clock::now();

    seconds s = duration_cast<seconds>(t2-t1);
    cout << s.count () << endl;
}

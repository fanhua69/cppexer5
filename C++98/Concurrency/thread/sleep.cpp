//
//  sleep.cpp
//  testcpp2
//
//  Created by hua fan on 2023-08-22.
//

#include <stdio.h>


#include <chrono>
#include <thread>
#include <iostream>


using namespace std;
using namespace chrono;

void sleepMain()
{
    steady_clock::time_point _begin = steady_clock::now();
    this_thread::sleep_until(_begin + milliseconds(50));
    steady_clock::time_point _end = steady_clock::now();

    nanoseconds s = duration_cast<nanoseconds> (_end-_begin);

    cout << "Slept nanoseconds:" << s.count() << endl;


    steady_clock::period p;
    cout << "den:" << p.den << endl;
    cout << "num:" << p.num << endl;

    std::ratio<1,100> a;
    cout << a.num << endl;
    cout << a.den << endl;

    system_clock c;
    high_resolution_clock cc;
    

}

#include "headers_2.h"
#include <iostream>
using namespace std;

void sleep_main()
{
}

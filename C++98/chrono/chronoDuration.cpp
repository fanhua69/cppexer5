//
//  chronoDuration.cpp
//  testcpp2
//
//  Created by hua fan on 2023-08-21.
//

#include <stdio.h>
#include <chrono>
#include "headers.h"
#include <thread>

using namespace std;
using namespace std::chrono;


void f()
{
    this_thread::sleep_for(seconds(3));
}

void durationTest()
{
    time_point <system_clock> p1 = system_clock::now();
    cout << typeid(p1).name() << endl;

    time_t t = system_clock::to_time_t(p1);
    cout << "done" << endl;
    cout << ctime(&t) << endl;


    for(int i = 0; i <10000000; i++)
    {
        int n = i * 2*123*14;
    }

    time_point<system_clock> p2 = system_clock::now();
    //auto d = p2 - p1;
    milliseconds d2 = duration_cast<milliseconds> (p2-p1);
    seconds d3 = duration_cast<seconds> (p2- p1);
    nanoseconds d5 = duration_cast<nanoseconds>(p2-p1);
    microseconds d6 = duration_cast<microseconds>(p2-p1);

    cout << "seconds:" << d3.count() << endl;
    cout << "milliseconds:" << d2.count() << endl;
    cout << "us:" << d6.count() << endl;
    cout << "nanoseconds: " << d5.count() << endl;

    //
    auto t1 = high_resolution_clock::now();
    f();
    auto t2 = high_resolution_clock::now();
    duration<double, micro> fp_ms = t2 - t1;
    cout << "micro fp_ms: " << fp_ms.count() <<  endl;

    duration<double, milli> fp_ms2 = t2 - t1;
    cout << "milli fp_ms: " << fp_ms2.count() <<  endl;


    duration<double, centi> fp_ms3 = t2 - t1;
    cout << "centi fp_ms: " << fp_ms3.count() <<  endl;

    duration<double, ratio<1, 1>> fp_ms4= t2-t1;
    cout << "1 fp_ms: " << fp_ms4.count() <<  endl;


    auto d1 = t2-t1;

    cout << "type: " << typeid(d1).name() << endl;
    cout << "count:" << d1.count() << endl;


    duration<double> d22 = t2-t1;
    cout <<"secondd:" << d22.count() << endl;

    t2 = t1+hours(1);
    hours da = duration_cast<hours>(t2-t1);
    cout << "hours:" << da.count() << endl;

    seconds ds = da;
    cout << "seconds: " << ds.count() << endl;


    std::this_thread::sleep_for(11113ms);

    
}

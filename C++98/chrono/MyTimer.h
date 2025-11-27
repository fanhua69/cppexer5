//
//  MyTimer.h
//  testcpp2
//
//  Created by hua fan on 2023-08-18.
//

#ifndef MyTimer_h
#define MyTimer_h


#include <stdio.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

class TimerClock
{
public:
    TimerClock()
    {
        update();
    }

    ~TimerClock()
    {
    }

    void update()
    {
        _start = high_resolution_clock::now();
        _startSystem = system_clock::now();
    }

    double getTimerSecond()
    {
        return getTimerMicroSec() * 0.000001;
    }

    double getTimerMilliSec()
    {
        return getTimerMicroSec() * 0.001;
    }

    long long getTimerMicroSec()
    {
        //return duration_cast<microseconds> (high_resolution_clock::now() - _start).count();
        return duration_cast<microseconds> (system_clock::now() - _startSystem).count();
    }

private:
    time_point<high_resolution_clock> _start;
    time_point<system_clock> _startSystem;
};

#endif /* MyTimer_h */

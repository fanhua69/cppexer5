//
//  chrono.cpp
//  testcpp2
//
//  Created by hua fan on 2023-08-18.
//

#include "headers.h"
#include "MyTimer.h"

void myTimermain()
{
    TimerClock TC;
    int sum = 0;
    TC.update();

    for (int i = 0; i < 10; i++)
    {
        for( int j = 0; j < 100; j++)
        {
            sum*=2;
            cout << sum << endl;
        }
    }

    double tms = TC.getTimerMilliSec();
    double tus = TC.getTimerMicroSec();
    cout << "cost time : " << tms << " ms " << endl;
    cout << "cost time : " << tus << " us " << endl;
}



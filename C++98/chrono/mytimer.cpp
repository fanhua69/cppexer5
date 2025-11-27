//
//  mytimer.cpp
//  testcpp2
//
//  Created by hua fan on 2023-08-22.
//

#include "mytimer.hpp"
#include "thread"
#include "headers.h"
using namespace std;

void mytimerMain()
{
    mytimer _time;
    _time.update();

    this_thread::sleep_for(seconds(1));

    cout << _time.getSecond();
}

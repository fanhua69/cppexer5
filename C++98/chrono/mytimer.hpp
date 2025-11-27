//
//  mytimer.hpp
//  testcpp2
//
//  Created by hua fan on 2023-08-22.
//

#ifndef mytimer_hpp
#define mytimer_hpp

#include <stdio.h>
#include <chrono>

using namespace std::chrono;

class mytimer
{
private:
    steady_clock::time_point _begin;
    steady_clock::time_point _end;

public:
    mytimer()
    {
        _begin = steady_clock::time_point();
        _end = steady_clock::time_point();
    }

    virtual ~mytimer(){};

    void update()
    {
        _begin = steady_clock::now();
    }

    double getSecond()
    {
        _end = steady_clock::now();
        duration<double> temp = duration_cast<duration<double>>(_end-_begin);
        return temp.count();
    }
};

#endif /* mytimer_hpp */

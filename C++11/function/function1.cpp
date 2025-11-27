//
//  function1.cpp
//  testcpp3
//
//  Created by hua fan on 2025-10-01.
//


#include "headers_2.h"
#include <iostream>
#include <functional>
#include <mutex>
#include <semaphore>

using namespace std;

namespace
{
class myfunctor
{
public:
    void operator()()
    {
        cout << " function operator called " << endl;
    }
    
};

std::mutex mt, mt2;
std::counting_semaphore<3> sem(3);
}



void function1_main()
{
    scoped_lock<mutex,mutex> lk(mt,mt2);
    std::function <void()> f4 = myfunctor();
    f4();
    
    auto t  = std::make_tuple(1,2,3);
    std::apply([](auto a, auto b, auto c) { cout << a + b + c << endl;}, t);
    std::apply([](auto a, auto b, auto c) { cout << a + b + c << endl;}, t);


    std::apply([](auto&&... elems) { ((cout << elems ),...);}, t);
    
    std::pair<int,int> p  = {1,2};
    auto p2 = std::make_pair(1,3);
    std::apply([](auto a, auto b){cout << a << b << endl;}, p2);
    
    
    
    
}

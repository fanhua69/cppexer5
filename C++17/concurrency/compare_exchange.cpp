//
//  compare_exchange.cpp
//  testcpp3
//
//  Created by hua fan on 2025-09-16.
//


#include "headers_2.h"
#include <iostream>
using namespace std;

namespace
{
std::atomic<int> stock{3};

bool buy(int nShares)
{
    int expected = 0;
    do {
        expected = stock.load();
        cout << expected << endl;
        if(expected < nShares ) return false;
    } while(!stock.compare_exchange_weak(expected, expected - nShares));
    
    return true;
}

}


void compare_exchange_main()
{
    buy(1);
    cout << stock.load() << endl;
    buy(1);
    cout << stock.load() << endl;
    buy(1);
    cout << stock.load() << endl;
    buy(1);
    cout << stock.load() << endl;


}

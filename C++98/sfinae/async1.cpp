//
//  async1.cpp
//  testcpp3
//
//  Created by hua fan on 2025-10-24.
//


#include "headers_2.h"
#include <iostream>
#include <future>

using namespace std;
namespace
{
int worker(int n)
{
    for(int i = 0; i < n ; i++)
    {
        cout << i << endl;
    }
    return n * 100;
}

}

void async31_main()
{
    std::future<int> f = std::async(std::launch::async, worker, 10);
    cout <<  f.get() << endl;
}

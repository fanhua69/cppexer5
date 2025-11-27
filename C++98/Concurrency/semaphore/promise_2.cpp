//
//  promise_2.cpp
//  testcpp3
//
//  Created by hua fan on 2025-01-01.
//

// Example program
#include <iostream>
#include <string>



#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <utility>
#include <future>
#include <thread>


using namespace std;

void tt(promise<int> &p)
{
    cout << "tt &" << endl;
    std::this_thread::sleep_for(1s);
    p.set_value(123);    
}

void gf(future<int> &f)
{
    cout << f.get() << endl;
}

int promise_2_main()
{
    std::promise<int> a;
    auto f = a.get_future();
    
    std::thread t2(gf, std::ref(f));
    std::thread t(tt, std::ref(a));
    t.join();
    t2.join();

     
    return 0;
}

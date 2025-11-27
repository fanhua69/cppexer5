//
//  atomic_ref1.cpp
//  testcpp3
//
//  Created by hua fan on 2025-09-10.
//

#include "headers_2.h"
#include <iostream>
#include <atomic>
#include <thread>

using namespace std;
#include <memory>
    
void atomic_ref1_main()
{

    int counter = 0; // 普通 int
    //std::atomic_ref<int> atomicCounter(counter); // 引用 counter
    
    auto task = [&]() {
        for (int i = 0; i < 1000; ++i) {
      //      atomicCounter.fetch_add(1, std::memory_order_relaxed);
        }
    };

    std::thread t1(task);
    std::thread t2(task);
    t1.join();
    t2.join();

    std::cout << "Final counter = " << counter << std::endl;
    
    string s("abcdefghijklmnopqrstuvwxyz");
    std::string_view sv(s);
    const char *d = sv.data();
    cout << typeid(d).name() << endl;
    cout << d << endl;
    for(int i = 0; i < 30; i++)
        cout << i << ", " << static_cast<int>(d[i]) << endl;
    
    // 输出 2000，且是线程安全的
    
    struct freedeleter{
        void operator()(int *p)
        {
            cout << "deleting" << endl;
            delete p;
        }
    };
    
    auto deleter = [](int* p){
        std::cout << "Deleting int\n";
        delete p;
    };
    
    std::unique_ptr<int, freedeleter> ppp (new int(10));
    std::shared_ptr<int> ppp3(new int (10), deleter);
    
    
}

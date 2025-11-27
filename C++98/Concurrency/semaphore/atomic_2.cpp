//
//  atomic_2.cpp
//  testcpp3
//
//  Created by hua fan on 2024-02-05.
//

#include <stdio.h>
#include <atomic>
#include "headers.h"

namespace concurrency
{

    struct A
    {
        float x;
        int y;
        long long z;
    };

    void atomic_2_main()
    {
        std::atomic<A> a;
        cout << std::boolalpha << a.is_lock_free() << endl;
    }

}

//
//  static_assert.cpp
//  testcpp3
//
//  Created by hua fan on 2024-02-24.
//

#include <stdio.h>
#include "headers.h"

void static_assert_main()
{
    static_assert(true, "asserted to be true");
    constexpr int i = 2;
    static_assert(i > 1);

    auto x = {3,4,5};
    cout << typeid(x).name() << endl;
}



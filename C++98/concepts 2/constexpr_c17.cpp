//
//  constexpr_c17.cpp
//  testcpp3
//
//  Created by hua fan on 2024-02-24.
//

#include <stdio.h>

#include "headers.h"


// https://github.com/0voice/cpp_new_features/blob/main/%E6%80%BB%E7%BB%93%E5%BD%92%E7%BA%B3%EF%BC%9AC%2B%2B17%E6%96%B0%E7%89%B9%E6%80%A7.md
template <bool ok>
constexpr void foo()
{
    if constexpr (ok == true)
    {
        cout << "OK " << endl;
    }
    else
    {
        cout << "NOT OK " << endl;
    }
}

void constexpr_c17_main()
{
    foo<true> ();
    foo<false> ();
    foo<1>();
}

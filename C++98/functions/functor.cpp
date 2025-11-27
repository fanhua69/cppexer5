//
//  functor.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-13.
//

#include <stdio.h>
#include "headers.h"

class FuncObjType
{
    public:
        template <typename ...Args>
        void operator ()(int m, Args... args)
        {
            cout << "hello " << endl;
            cout << m << endl;
            cout << (args / ...) << endl;
        }

        int n;
};

consteval int sqr(int n)
{
    return n * n;
}


void functor_main()
{
    FuncObjType t;
    t(1,2,3);

    int n = 12;
    constexpr int r = sqr(10);
    cout << r << endl;
}


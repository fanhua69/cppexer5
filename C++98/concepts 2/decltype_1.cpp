//
//  decltype_1.cpp
//  testcpp3
//
//  Created by hua fan on 2024-02-17.
//

#include <stdio.h>


#include "headers.h"

void decltype_1_main()
{
    int n = 10;
    int &r1 = n;

    // auto type duction:
    auto r2 = r1;
    r2 = 20;
    cout << n << ", " << r1 << ", " << r2 << endl;
    cout << typeid(r2).name() << endl;
    cout << typeid(r1).name() << endl;

    // decltype type deduction:
    decltype(r1) r3 = n;
    r3 = 88;
    cout <<n << ", " << r1 << ", " << r3 << endl;
    cout << typeid(r3).name() << endl;


    /////////////////////////////////////////
    ///
    const int n1 = 0;
    auto n2 = 10;
    n2 = 99;

    decltype(n1) n3 = 20;
    //    n3 = 5;  // doesn't compile


    // Pointers:
    const int *p1 = &n1;

    auto p2 = p1;
    //     *p2 = 77; don't compile



    decltype(p1) p3 = p1;
    // *p3 = 19; don't compile



}

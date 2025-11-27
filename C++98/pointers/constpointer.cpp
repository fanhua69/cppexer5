//
//  constpointer.cpp
//  testcpp2
//
//  Created by hua fan on 2023-08-24.
//

#include <stdio.h>

#include "headers.h"

void pointertest()
{
    int i= 0;
    int * const p = &i;

    *p = 2;

    cout << i << endl;


    const int a = 3;
    const int *p2 = &a;

}

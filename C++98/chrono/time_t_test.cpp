//
//  time_t_test.cpp
//  testcpp2
//
//  Created by hua fan on 2023-08-21.
//

#include <stdio.h>
#include "headers.h"

#define __STDC_WANT_LIB_EXT1__ 1
#include <time.h>



void time_t_test()
{
    time_t a;
    time(&a);

    cout << ctime(&a) << endl;


    for(int i = 0; i< 2009119999; i++)
    {
        int a = 12*123*23;
    }

    time_t b;
    time(&b);
    cout << "seconds: " << b - a << endl;


}

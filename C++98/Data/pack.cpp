//
//  pack.cpp
//  testcpp3
//
//  Created by hua fan on 2023-12-26.
//

#include <stdio.h>
#include <iostream>
#include "headers.h"


#pragma pack(push, 1)
#pragma pack(show)

struct A
{
    char a;
    int b;
    char d[11];
    char c;
};


void pack_main()
{
    cout << sizeof(int) << endl;
    cout << sizeof(A) << endl;
    cout << alignof(A) << endl;
    cout << "alv :" << std::alignment_of<A>::value << endl;
    cout << std::alignment_of<A>() << endl;
    
}

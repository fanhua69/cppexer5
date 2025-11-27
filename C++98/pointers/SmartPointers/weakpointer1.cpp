//
//  weakpointer1.cpp
//  testcpp2
//
//  Created by hua fan on 2023-11-10.
//

#include <stdio.h>
#include <iostream>
#include <memory>
#include "headers.h"

void weakPointerMain()
{
    std::shared_ptr<int> sptr;

    sptr.reset(new int);
    *sptr = 10;

    std::weak_ptr<int> weak1 = sptr;
//    sptr.reset(new int);
  //  *sptr = 5;

    std::weak_ptr<int> weak2 = sptr;
    if(auto tmp = weak1.lock())
    {
        std::cout << "weak1 value is : " << *tmp << endl;
        *tmp = 20;
        cout << *sptr;
    }
    else
        cout << "weak1 is expired " << endl;

    if(auto tmp = weak2.lock())
        std::cout << "weak2 value is : " << *tmp << endl;
    else
        cout << "weak2 is expired " << endl;
}

//
//  stackInil.cpp
//  testcpp2
//
//  Created by hua fan on 2023-09-07.
//

#include <stdio.h>
#include "headers.h"

void stackInit()
{
    std::vector<int> v(10,-1);

    std::stack<int,vector<int>> myStack(v);
    myStack.push(1);
    myStack.push(2);

    print(myStack);



}

//
//  for_loop.cpp
//  testcpp3
//
//  Created by hua fan on 2024-02-18.
//

#include <stdio.h>
#include "headers.h"
#include <list>

string getString()
{
    cout << "Get String : " << endl;
    return "abcde";
}


void for_loop_main()
{
    std::list<int> l{1,2,3,4,5};
    std::list<int> l2{6,7,8,9,10};
    auto it = l.end();
    l.splice(it, l2);

    print(l);
    cout << "over" << endl;
    print(l2);
}


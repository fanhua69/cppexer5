//
//  findInMap.cpp
//  testcpp2
//
//  Created by hua fan on 2023-09-12.
//

#include <stdio.h>

#include "headers.h"


void findInMap()
{
    map<int,int> m{{1,11},{2,22}};

    auto it = m.find(13);

    int n = it==m.end()?-1: it->second;

    cout << n << endl;

    print(m);

}

//
//  vectorsize.cpp
//  testcpp2
//
//  Created by hua fan on 2023-09-01.
//

#include <stdio.h>
#include "headers.h"
#include <algorithm>

extern int g_exerterna ;

namespace
{
struct Sum
{
    int all;
    void operator()(int x)
    {
        all+=x;
    }
};
}

void vectorMain()
{
    vector<int> v{1,2,11,3,4,5,1,1,2,2};
    auto s = for_each(v.begin(), v.end(), Sum());
    cout << s.all << endl;
}

//
//  par_unsep.cpp
//  testcpp3
//
//  Created by hua fan on 2025-09-15.
//


#include "headers_2.h"
#include <iostream>
#include <algorithm>
#include <execution>



using namespace std;

void par_unsep_main()
{
    vector<int> v{1,2,3,4,5,6};
    for_each(v.begin(), v.end(), [](auto &a){cout << a << endl;});
}

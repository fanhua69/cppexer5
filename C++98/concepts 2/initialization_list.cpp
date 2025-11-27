//
//  initialization_list.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-28.
//

#include <stdio.h>
#include <vector>
#include "headers.h"

class fooi
{
    public:
        fooi(int a, int b, int c)
        {
        }
};


void initialization_list_main()
{
    fooi a({1,2,3});
    fooi a2 = {1,2,3};
    fooi a3 {1,2,3};

    vector<int> a4 {1,3,34};
    vector<int> a5 = {1,2,3};
    vector<int> a6({1,2,3});

}

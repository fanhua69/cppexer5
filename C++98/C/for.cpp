//
//  for.cpp
//  testcpp2
//
//  Created by hua fan on 2023-08-31.
//

#include <stdio.h>
#include "headers.h"

void forMain()
{
    vector<int> v{1,2,3,4,5};
    for(int i =0; i<v.size(); i++)
    {
        cout << v[i] << endl;
        v.insert(v.end(), i*2);
    }
}

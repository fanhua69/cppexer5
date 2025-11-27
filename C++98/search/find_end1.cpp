//
//  find_end1.cpp
//  testcpp3
//
//  Created by hua fan on 2025-09-12.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include "headers_2.h"
#include <iostream>
using namespace std;
    

#include "headers_2.h"
#include <iostream>
using namespace std;
    
void find_end1_main()
{
    std::vector<int> v{1,2,2,2,2,3,4,5};
    auto it = std::find(v.rbegin(), v.rend(), 2);
    if(it != v.rend())
    {
        cout << v.rend() - it - 1 << endl;
    }

}

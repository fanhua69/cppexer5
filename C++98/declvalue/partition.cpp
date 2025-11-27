//
//  partition.cpp
//  testcpp3
//
//  Created by hua fan on 2025-07-21.
//

#include "headers_2.h"
#include <iostream>
#include <algorithm>


using namespace std;
    
void partition_main()
{
    vector<int> f {1,2,2,3,4,5,6};
    std::partition(f.begin(), f.end(), [](int x) { return x%2 == 1;});
    print(f);
    cout << endl;
    
    bool result = std::is_partitioned(f.begin(), f.end(), [](int x){ return x % 2 == 1;});
    print(result);
    
    vector<int> odd, even;
    std::partition_copy(f.begin(), f.end(), std::back_inserter(odd), std::back_inserter(even), [](int x){ return x % 2 == 1;});
    
    print(odd);
    print(even);
    
        
        
}

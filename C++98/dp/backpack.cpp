//
//  backpack.cpp
//  testcpp3
//
//  Created by hua fan on 2025-08-28.
//

#include "headers_2.h"
#include <iostream>
using namespace std;

int maxpack(const vector<int>& weight, const vector<int>& value, int cap)
{
    if(weight.size() != value.size() || weight.size() == 0 || cap <= 0)
        return 0;
    
    vector<int> dp (cap + 1, -1);
    dp [0] = 0;
    
    for(int i = 0; i < weight.size(); i++)
    {
        int w = weight[i];
        int v = value[i];
        
        for(int j = cap; j >= w; j --)
        {
            if(dp[j-w]!=-1)
            {
                dp[j] = max(dp[j], dp[j-w] + v);
            }
        }
    }
    
    return *std::max_element(dp.begin(), dp.end());
}
    
void backpack_main()
{
}

//
//  split_vector.cpp
//  testcpp3
//
//  Created by hua fan on 2025-08-28.
//

#include "headers_2.h"
#include <iostream>
using namespace std;
    

#include <vector>
#include <numeric> // for std::accumulate
#include <algorithm> // for std::max
#include <iostream>

int minPartitionDifference(const std::vector<int>& nums, int target)
{
    vector<int> dp(target + 1, -1);
    dp[0]= 0;
    
    for(auto n : nums)
    {
        for(int i = target; i >= n; i--)
        {
            if(dp[i-n] != -1)
            {
                dp[i] = max(dp[i], dp[i - n] + n * n);
            }
        }
    }
    
    int m = 0;
    for(auto n : dp)
        m = max(m, n);
    
    return m;
    
}

void split_vector_main()
{
    std::vector<int> nums = {1, 2, 3, 4};
    std::cout << "最小差: " << minPartitionDifference(nums, 3) << std::endl; // 输出 1
    return;
}

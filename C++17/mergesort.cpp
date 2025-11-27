//
//  mergesort.cpp
//  testcpp3
//
//  Created by hua fan on 2025-09-11.
//

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <thread>
#include "headers_2.h"
#include <iostream>

using namespace std;

std::vector<int> merge(vector<vector<int>> &arr)
{
    int N = arr.size();
    std::vector<int> res;
    std::priority_queue<pair<int,int>, vector<pair<int,int>>, std::greater<>> q;

    vector<int> indexs(N, 0);
    for(int i = 0; i < N; i++)
    {
        q.push(pair<int,int>(arr[i][indexs[i]], i));
    }
    
    while(!q.empty())
    {
        auto [v, j] = q.top();
        q.pop();
        res.push_back(v);
        indexs[j]++;

        if(indexs[j] < arr[j].size())
        {
            q.push({arr[j][indexs[j]], j});
        }
    }

    return res;
}

    
void mergesort_main()
{
    std::vector<int> v1{1,2,3,7,8,9};
    std::vector<int> v2{4,5,6};
    std::vector<int> v3{4,5,6};
    
    vector<vector<int>> p{v1,v2, v3};
    auto v = merge(p);
    print(v);
}

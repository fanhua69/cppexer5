//
//  deque2.cpp
//  testcpp3
//
//  Created by hua fan on 2025-09-19.
//


#include "headers_2.h"
#include <iostream>
#include <deque>
#include <algorithm>
#include <queue>


using namespace std;

void deque3_main()
{
    std::deque<int> q;
    std::queue<int> r;
    
    q.push_front(1);
    q.push_back(2);
    q.emplace_front(3);
    q.emplace_back(4);
    
    print(q);
    
    std::sort(q.begin(), q.end());
    print(q);
    
    auto it = std::find(q.begin(), q.end(), 11232);
    if(it != q.end())
        cout << *it << endl;
    else
        print("Not found");
    
    auto n = std::count(q.begin(), q.end(), 2);
    cout << n << endl;
    
    std::copy_backward(q.begin(), q.begin() + 3, q.end());
    print(q);
    
}

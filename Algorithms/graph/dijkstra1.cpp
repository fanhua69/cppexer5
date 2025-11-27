//
//  dijkstra1.cpp
//  testcpp3
//
//  Created by hua fan on 2025-10-07.
//


#include "headers_2.h"
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;


int find_shortest_path(vector<vector<int>> &g, int from, int to)
{
    std::unordered_map <int,vector<pair<int,int>>> m;
    std::unordered_map <int, int> w;
    for(auto v: g)
    {
        m[v[0]].push_back({v[1], v[2]});
        w[v[0]] = INT_MAX;
        w[v[1]] = INT_MAX;
    }
    
    std::priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> distances;
    distances.push(make_pair(0, from));
    w[from] = 0;
    
    while(distances.size())
    {
        auto [weight, vertex] = distances.top(); distances.pop();
        
        if(weight > w[vertex]) continue;
        
        for(auto &p : m[vertex] )
        {
            if( w[vertex] + p.second <  w[p.first] )
            {
                w[p.first] = w[vertex] + p.second;
                distances.push({w[p.first], p.first});
            }
        }
    }
    
    return w[to];
}

namespace
{

class test
{
public:
    void show()
    {
        cout << "showing data test" << endl;
        cout << m_data << endl;
    };
    
    static void showw()
    {
        cout << "show static funciton " << endl;
    }
    
    int m_data = 10;
};

}

void dijkstra1_main()
{
    static test a;
    a.show();
    a.showw();
    
    vector<vector<int>> g = {
         {0, 1, 4},
         {0, 2, 1},
         {2, 1, 2},
         {1, 3, 1},
         {2, 3, 5}
     };
     cout << find_shortest_path(g, 0, 3) << endl; // 输出 4
}

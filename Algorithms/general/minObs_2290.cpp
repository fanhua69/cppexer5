//
//  minObs_2290.cpp
//  testcpp3
//
//  Created by hua fan on 2024-11-28.
//
#include <map>
#include <vector>
#include <unordered_map>
#include "print.h"
#include <queue>

#include <iostream>

using namespace std;


    pair<int,int> minDis(map<int, int> &dis, int C)
    {
        if(dis.size() == 0)
            return {0,0};
        
        auto it = dis.begin();
        int K = it->second;
        int r = K / C;
        int c = K % C;
        return make_pair(r,c);
    }

    void calcw( vector<vector<int>> &g, int w, int i, int j, int R, int C,
                unordered_map<int,int> &td,
                unordered_map<int,int> &gw,
                map<int,int> &rgw)
    {
        if (i < 0 || i >= R || j < 0 || j >= C)
            return;

        int k = i * C + j;

        w+=g[i][j];

        if ( !td.count(k) && (!gw.count(k) || w < gw[k]))
        {
            gw[k] = w;        
            rgw[w] = k;
        }
    }
    
    int minimumObstacles(vector<vector<int>>& grid) 
    {
        int R, C;

        R = grid.size();
        if (R ==0 )
            return 0;

        C = grid[0].size();
        if (C == 0)
            return 0;

        unordered_map<int,int> gw;
        map<int,int> rgw;
        gw[0] = 0;
        rgw[0] = 0;


        unordered_map<int, int> td;
        int k = 0, w;
        while(rgw.size() > 0)
        {
            pair<int,int> p = minDis(rgw, C);
            int i = p.first;
            int j = p.second;
            k =  p.first * C + p.second;
            w = gw[k];
            td[k] = w;
            rgw.erase(rgw.begin());

            calcw(grid, w, i, j + 1, R ,C, td, gw, rgw);
            calcw(grid, w, i, j - 1, R ,C, td, gw, rgw);
            calcw(grid, w, i - 1, j, R ,C, td, gw, rgw);
            calcw(grid, w, i + 1, j, R ,C, td, gw, rgw);

            //cout << gw.size() << " , ";
        }

        int K = (R-1) * C + (C-1);


        return td[K];
    }


void minObs_2290_main()
{
    vector<vector<int>> grid {{0, 1, 0, 0, 0}, {0, 1, 0, 1, 0}, {0, 0, 0, 1, 0}};

    pair<int, vector<int>> a{1, {1,2,3}};
    pair<int, vector<int>> b{1, {2,3,3}};
    if ( a < b)
    {}

    vector<int> c{1,2,3};
    vector<int> d{1,2,3};



    if(!std::greater<>()(a, b))
    {
        cout << "smaller" << endl;
    }

    std::priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
    pq.push({1,2,3});
    pq.push({1,2,3});
    pq.push({1,2,3});



    cout << minimumObstacles(grid) << endl;
}

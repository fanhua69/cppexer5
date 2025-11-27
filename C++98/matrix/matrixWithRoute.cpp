//
//  matrixWithRoute.cpp
//  testcpp2
//
//  Created by hua fan on 2023-08-13.
//

#include <stdio.h>
#include "headers.h"


vector<vector<pair<int,int>>>
getRoutes( const vector<vector<bool>> &matrix,
           vector<pair<int,int>> route,
           int cr,
           int cc,
           int tr,
           int tc)
{
    if(cr < 0 || cr >= tr || cc < 0 || cc >= tc || !matrix[cr][cc] )
    {
        return vector<vector<pair<int,int>>> {};
    }

    vector<vector<pair<int,int>>> rs;

    route.push_back(make_pair(cr,cc));

    if(cr == tr -1 && cc == tc-1)
    {
        rs.push_back(route);
        return rs;
    }

    auto routeRight = getRoutes(matrix, route, cr, cc+1, tr, tc);
    rs.insert(rs.begin(), routeRight.begin(), routeRight.end());
    auto routeDown = getRoutes(matrix, route, cr+1, cc, tr, tc);
    rs.insert(rs.begin(), routeDown.begin(), routeDown.end());

    return rs;
}



void matrixWithRouteMain()
{
    vector<vector<bool>> a{{true, true, true},
                           {true, false, true},
                           {true, true, true}};

    vector<pair<int,int>> r;
    vector<vector<pair<int,int>>> result =
        getRoutes(a, r, 0, 0 ,a.size(), a[0].size());

    print(result);
    cout << endl;


    vector<pair<int,int>> v{{1,2},{2,3},{3,4}};
    print(v);

    cout << endl;

    vector<vector<int>> v2{{1,2},{2,3},{3,4}};
    print(v2);
}

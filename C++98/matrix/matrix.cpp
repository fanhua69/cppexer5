//
//  matrix.cpp
//  testcpp2
//
//  Created by hua fan on 2023-08-10.
//

#include <stdio.h>
#include "headers.h"


int help(const vector<vector<bool>> &matrix, int tr, int tc, int r, int c)
{
    if(r < 0 || r >= tr || c < 0 || c >= tc || !matrix[r][c])
        return 0;

    if(r == tr-1 && c == tc -1 )
        return 1;

    return help(matrix, tr, tc, r, c+1) + help(matrix, tr, tc, r+1, c);
}

int getRouteCount(const vector<vector<bool>> & matrix)
{
    return help(matrix, matrix.size(), matrix[0].size(), 0,0);
}

void matrixMain()
{
    vector<vector<bool>> a{{true, true, true},
                           {true, true, true},
                           {true, true, true}};

    cout << getRouteCount(a) << endl;
}

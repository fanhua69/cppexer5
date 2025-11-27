//
//  MatrixPath.cpp
//  testcpp2
//
//  Created by hua fan on 2023-09-30.
//

#include <stdio.h>
#include "headers.h"


int findPath(vector<vector<int>> &matrix)
{
    int R = matrix.size();
    int C = matrix[0].size();


    for(int i = 1; i < C; i++)
        if( matrix[0][i-1] == 0)
            matrix[0][i] = 0;


    for(int i = 1; i < R; i++)
        if(matrix[i-1][0] == 0)
            matrix[i][0] = 0;


    for(int i = 1; i < R; i++)
    {
        for(int j = 1; j < C; j++)
        {
            if(matrix[i][j] == 1)
            {
                matrix[i][j] = matrix[i-1][j] + matrix[i][j-1];
            }
        }
    }


    return matrix[R-1][C-1];
}

int findPath2(vector<vector<int>> &matrix)
{
    int R = matrix.size();
    int C = matrix[0].size();

    for (int i = C -2; i >=0; i--)
        if (!matrix[R-1][i+1])
            matrix[R-1][i] = 0;

    for (int i = R-2; i>=0; i--)
        if(!matrix[i+1][C-1])
            matrix[i][C-1] = 0;

    for (int i = R-2; i>=0; i--)
    {
        for ( int j = C-2; j >=0; j--)
        {
            if(matrix[i][j] )
                matrix[i][j] = matrix[i+1][j] + matrix[i][j+1];
        }
    }

    return matrix[0][0];
}

void findMatrixPathMain()
{
    vector<vector<int>> matrix({{1,1,1},{1,1,1},{1,1,1}});
    cout << findPath2(matrix) << endl;

}

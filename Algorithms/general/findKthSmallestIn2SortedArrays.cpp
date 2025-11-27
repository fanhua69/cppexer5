//
//  findKthSmallestIn2SortedArrays.cpp
//  testcpp3
//
//  Created by hua fan on 2024-12-16.
//
#include <vector>
#include <iostream>

using namespace std;


int solve(  vector<int>& A,
            vector<int>& B,
            int k,
            int aStart, int aEnd,
            int bStart, int bEnd)
{
    // If the segment of on array is empty, it means we have passed all
    // its element, just return the corresponding element in the other
    // array.
    if (aEnd < aStart)
    {
        return B[k - aStart];
    }

    if (bEnd < bStart)
    {
        return A[k - bStart];
    }

    // Get the middle indexes and middle values of A and B.
    int aIndex = (aStart + aEnd) / 2;
    int bIndex = (bStart + bEnd) / 2;
    int aValue = A[aIndex];
    int bValue = B[bIndex];

    // If k is in the right half of A + B, remove the smaller left half.
    if (aIndex + bIndex < k)
    {
        if (aValue > bValue)
        {
            return solve(A, B, k, aStart, aEnd, bIndex + 1, bEnd);
        }
        else
        {
            return solve(A, B, k, aIndex + 1, aEnd, bStart, bEnd);
        }
    }
    // Otherwise, remove the larger right half.
    else
    {
        if (aValue > bValue)
        {
            return solve(A, B, k, aStart, aIndex - 1, bStart, bEnd);
        }
        else
        {
            return solve(A, B, k, aStart, aEnd, bStart, bIndex - 1);
        }
    }
    return -1;
}

void findKthSmallestIn2SortedArrays_main()
{
    vector<int> a {0,1,2,3,4};
    vector<int> b {0,1,2,3,4};
    cout << solve(a, b, 4, 0, a.size() - 1, 0, b.size() - 1) << endl;
}

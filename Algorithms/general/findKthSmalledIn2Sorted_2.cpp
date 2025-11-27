//
//  findKthSmalledIn2Sorted_2.cpp
//  testcpp3
//
//  Created by hua fan on 2024-12-17.
//
#include <vector>
#include <iostream>

using namespace std;

int solve2(  vector<int>& A, vector<int>& B, int k)
{
    // If the segment of on array is empty, it means we have passed all
    // its element, just return the corresponding element in the other
    // array.
    if (A.size() == 0)
    {
        return B[k - 1];
    }

    if (B.size() == 0)
    {
        return A[k - 1];
    }

    // Get the middle indexes and middle values of A and B.
    int aIndex = A.size() / 2;
    int bIndex = B.size() / 2;
    int aValue = A[aIndex];
    int bValue = B[bIndex];

    // If k is in the right half of A + B, remove the smaller left half.
    if (aIndex + bIndex + 2 <= k)
    {
        if (aValue > bValue)
        {
            vector<int> b2 { B.begin() + bIndex + 1, B.end()};
            return solve2(A, b2, k - (bIndex + 1) );
        }
        else
        {
            vector<int> a2{A.begin() + aIndex + 1, A.end()};
            return solve2(a2, B, k - (aIndex +1));
        }
    }
    // Otherwise, remove the larger right half.
    else
    {
        if (aValue > bValue)
        {
            vector<int> a2 {A.begin(), A.begin() + aIndex };
            return solve2(a2, B, k);
        }
        else
        {
            vector<int> b2{B.begin(), B.begin() + bIndex};
            return solve2(A, b2, k);
        }
    }
    return -1;
}

int kth(vector<int> &a, int af, vector<int> &b, int bf, int k)
{
    if(af >= a.size())
        return b[bf + k -1];
    if(bf >= b.size())
        return a[af + k -1];
    
    if (k == 1)
    {
        return min(a[af], b[bf]);
    }
    
    int ai = af + k/ 2  - 1;
    int ad = ai >= a.size() ? INT_MAX : a[ai];
    int bi = bf + k / 2 - 1;
    int bd = bi >= a.size() ? INT_MAX : b[bi];
    
    if(ad < bd)
    {
        return kth(a, ai + 1, b , bf, k - k / 2);
    }
    else
    {
        return kth(a, af, b,  bi + 1, k - k / 2);
    }
}


int kth2(const vector<int>& A, int aStart,
        const vector<int>& B, int bStart,
        int k)
{
    // k 是第 k 小（从 1 开始）
    
    // 如果 A 用完了，直接在 B 中取
    if (aStart >= A.size())
        return B[bStart + k - 1];
    // 如果 B 用完了
    if (bStart >= B.size())
        return A[aStart + k - 1];

    // k == 1 时，取两数组当前最小的
    if (k == 1)
        return min(A[aStart], B[bStart]);

    // 取 A 和 B 的第 k/2 个元素（注意可能越界）
    int aKey = (aStart + k/2 - 1 < A.size()) ?
               A[aStart + k/2 - 1] : INT_MAX;
    int bKey = (bStart + k/2 - 1 < B.size()) ?
               B[bStart + k/2 - 1] : INT_MAX;

    if (aKey < bKey)
    {
        // 丢掉 A 的 k/2 个元素
        return kth2(A, aStart + k/2, B, bStart, k - k/2);
    }
    else
    {
        // 丢掉 B 的 k/2 个元素
        return kth2(A, aStart, B, bStart + k/2, k - k/2);
    }
}
int solve2_optimized(vector<int>& A, vector<int>& B, int k)
{
    return kth(A, 0, B, 0, k);
}

void findKthSmallestIn2SortedArrays2_main()
{
    vector<int> a {1,2,3,4};
    vector<int> b {5,6};
    cout << solve2_optimized(a, b, 5) << endl;
}

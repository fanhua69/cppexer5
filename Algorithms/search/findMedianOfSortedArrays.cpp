//
//  findMedianOfSortedArrays.cpp
//  testcpp3
//
//  Created by hua fan on 2024-06-02.
//

#include <stdio.h>
#include "headers.h"

template <typename H>
concept Heap = requires(H& h, const H& ch)
{
    typename H::value_type;
    typename H::container_type;
    {ch.empty()}->std::convertible_to<bool>;
    {ch.size()}->std::convertible_to<std::size_t>;
    {ch.top()}->std::same_as<const typename H::value_type&>;
    
    {h.push(std::declval<const typename H::value_type&>())}->std::same_as<void>;
    {h.pop()}->std::same_as<void>;
};

template<typename  HEAP_LEFT, typename HEAP_RIGHT>
requires Heap<HEAP_LEFT> and Heap<HEAP_RIGHT>
void rebalance(HEAP_LEFT  &l, size_t ll,
               HEAP_RIGHT &r, size_t lr)
{
    while(ll < lr + 1)
    {
        auto&& d = std::move(const_cast<HEAP_RIGHT::value_type&>(r).pop());
        r.pop();
        l.push(d);
        lr --;
        ll ++;
    }
}

double findMedianSortedArrays(vector<int>& a, vector<int>& b)
{
    if(a.size() > b.size())
        return findMedianSortedArrays(b,a);
    
    int ltc = (a.size() + b.size() + 1) / 2;
    int left = -1, right = a.size();
    while(left + 1 < right)
    {
        int lmid = left + (right - left ) / 2 ;
        int rmid = ltc - lmid - 2;
        
        if (a[lmid] > b[rmid + 1])
        {
            right = lmid;
        }
        else
        {
            left = lmid;
        }
    }
    

    int r = ltc - left - 2;
    int dla = left == -1           ? INT_MIN : a[left];
    int dlb = r    == -1           ? INT_MIN : b[r];
    int dra = left == a.size() - 1 ? INT_MAX : a[left + 1];
    int drb = r    == b.size() - 1 ? INT_MAX : b[r + 1];
    
    if ( (a.size () + b.size()) % 2 == 0)
    {
        return (max(dla, dlb) + min(dra, drb)) /2.0;
    }
    else
    {
        return max(dla, dlb);
    }
}

void findMedianOfSortedArraysMain()
{
    vector<int> v1, v2;
    double d;
    
    v1 = {2};
    v2 = {3,4,5,6};
    d = findMedianSortedArrays(v1, v2);
    cout << d << endl;

    
    v1 = {1,2,3};
    v2 = {100};
    d = findMedianSortedArrays(v1, v2);
    cout << d << endl;

    v1 = {1,2,3};
    v2 = {4};
    d = findMedianSortedArrays(v1, v2);
    cout << d << endl;
//
//    v1 = {1,3,5,7,9};
//    v2 = {2,4,6,8,10};
//    d = findMedianSortedArrays(v1, v2);
//    cout << d << endl;
//    
//    v1 = {1,2,3,4,5};
//    v2 = {3,4,5,6,7};
//    d = findMedianSortedArrays(v1, v2);
//    cout << d << endl;
//    
//    v1 = {1,2,3,4,5};
//    v2 = {6,7,8,9,10};
//    d = findMedianSortedArrays(v1, v2);
//    cout << d << endl;
//    
//    v1 = {1,2,3,4,5};
//    v2 = {6,7,8,9,10,11,12};
//    d = findMedianSortedArrays(v1, v2);
//    cout << "a:" << d << endl;
//    
//    v1 = {6,7,8,9,10};
//    v2 = {1,2,3,4,5};
//    d = findMedianSortedArrays(v1, v2);
//    cout << d << endl;
//
//    v1 = {1,2,3};
//    v2 = {4,5,6,7,8,9};
//    d = findMedianSortedArrays(v1, v2);
//    cout << d << endl;
//    
//    v2 = {1,2,3};
//    v1 = {4,5,6,7,8,9};
//    d = findMedianSortedArrays(v1, v2);
//    cout << d << endl;
}

#include "headers_2.h"
#include <iostream>
using namespace std;

void findMedianOfSortedArrays_main()
{
}

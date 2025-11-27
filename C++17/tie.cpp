//
//  tie.cpp
//  testcpp3
//
//  Created by hua fan on 2025-06-24.
//

#include "headers_2.h"
#include <iostream>
using namespace std;
    
void tie_main()
{
    int a= 3, b = 4;
    auto t = std::tie(a,b);
    
    auto &[x,y] = t;
    x = 55;
    cout << a << endl;
    
    auto [x1,y1] = t;
    x1 = 22;
    cout << a << endl;
    
    std::set<int> ms;
    auto [it, inserted] = ms.insert(10);
    cout << *it << ", " << inserted << endl;

    std::tie(it, inserted) = ms.insert(10);
    cout << *it << ", " << inserted << endl;
    
    double arr [3] = {1,2,3};
    auto [ a1, b1, c1] = arr;
    cout << a1 << ", " << b1 << ", " << c1 << endl;
    
    struct point
    {
        double x;
        double y;
    };
    auto p11 = point(1,2);
    
    auto &[p111, p222] = p11;
    cout << p111 << ", " << p222 << endl;
    p111 = 1234;
    cout << p11.x << endl;
    
    pair<int,float> p31{1,3.14};
    auto [x11,y11] = p31;
    x11 = 2;
    y11 = 5.55;
    cout << p31.first << ", " << p31.second << endl;
     
    
}

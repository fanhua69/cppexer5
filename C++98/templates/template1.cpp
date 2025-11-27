//
//  template1.cpp
//  testcpp3
//
//  Created by hua fan on 2025-10-07.
//

template <typename T>
T testadd(T a, T b)
{
    return a + b;
}

template int testadd<int>(int,int);
//template double add<double>(double,double);

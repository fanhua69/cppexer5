//
//  integer_sequence.cpp
//  testcpp3
//
//  Created by hua fan on 2025-01-06.
//

#include <utility>
#include <iostream>

using namespace std;

template <typename T>
void fun1(const T& t){
    cout << t << '\n';
}

template <typename T, typename ... Args>
void fun1(const T& t, Args ... args){
    cout << t << ',';
    fun1(args...);//递归解决，利用模板推导机制，每次取出第一个，缩短参数包的大小。
}

void integer_sequence_1_main()
{
    fun1(1,2,3);
}




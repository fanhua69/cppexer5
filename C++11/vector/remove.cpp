//
//  remove.cpp
//  testcpp3
//
//  Created by hua fan on 2025-09-19.
//


#include "headers_2.h"
#include <iostream>
using namespace std;

void remove1_main()
{
    std::vector<int> v;
       v.reserve(2); // 预留容量为2

       // 插入前打印容量
       std::cout << "Initial capacity: " << v.capacity() << std::endl;

       // 插入第一个元素
       v.push_back(1);
       auto it = v.begin(); // 保存第一个元素的迭代器
       std::cout << "After push_back(1): *it = " << *it
                 << ", capacity = " << v.capacity() << std::endl;

       // 插入第二个元素
       v.push_back(2);
       std::cout << "After push_back(2): *it = " << *it
                 << ", capacity = " << v.capacity() << std::endl;

       // 插入第三个元素，触发容量增长
       v.push_back(3);
       std::cout << "After push_back(3): capacity = " << v.capacity() << std::endl;

       // 再次访问之前保存的迭代器
       std::cout << "After growth, *it (may be invalid!) = " << *it << std::endl;

       return ;
}

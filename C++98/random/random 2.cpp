//
//  random.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-28.
//

#include <stdio.h>
#include <random>
#include <time.h>
#include "headers.h"
#include <algorithm>
#include <functional>


// https://blog.csdn.net/weixin_43919932/article/details/119994136

// https://zhuanlan.zhihu.com/p/537101533

// https://www.cnblogs.com/jiading/p/11653911.html



void fun()
{
    srand((unsigned int)time(nullptr)); // 使用秒作为随机种子
    std::cout << "time:" << (unsigned int)time(nullptr) << std::endl;
    std::cout << "random:" << rand() << std::endl;
}

void random_main()
{

    int i = 10;
    while (i--)
    {
        fun();
    }
    

    std::random_device rd;
    cout << "random:" << rd() << endl;
    cout << "random:" << rd() << endl;
    cout << "random:" << rd() << endl;
    cout << "random:" << rd() << endl;
    cout << "random:" << rd() << endl;

    std::random_device rd2;// 真实随机数产生器
    std::mt19937 mt(rd2());//生成计算随机数mt
    cout << "mt:" << mt() << endl;
    std::uniform_int_distribution<long long> dist(-1000,1000);
    cout << dist(mt) << endl;
    //生成-1000到1000之间的离散均匀分布数

    auto rnd = std::bind(dist, mt);


    cout << rnd() <<endl;


    std::mt19937 mt2(rd2());
    std::uniform_int_distribution<int> ddd(-10, 10);
    auto rrr = std::bind(ddd, mt2);
    cout << rrr() << endl;


}

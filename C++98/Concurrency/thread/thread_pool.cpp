//
//  thread_pool.cpp
//  testcpp3
//
//  Created by hua fan on 2024-02-05.
//

#include <stdio.h>
#include <future>
#include <thread>
#include <functional>
#include <queue>
#include <iostream>
#include <random>
#include "thread_pool.hpp"


//  https://zhuanlan.zhihu.com/p/367309864

namespace concurency
{
    std::random_device rd;// 真实随机数产生器
    std::mt19937 mt(rd());//生成计算随机数mt
    std::uniform_int_distribution<int> dist(-1000,1000);
    //生成-1000到1000之间的离散均匀分布数

    auto rnd = std::bind(dist, mt);

    void simulate_hard_computation();


    void future_1_main()
    {

    }
}

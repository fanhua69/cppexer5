//
//  variant_visit.cpp
//  testcpp3
//
//  Created by hua fan on 2024-02-01.
//

#include <stdio.h>
#include <variant>
#include "headers.h"

// https://blog.csdn.net/qq_21438461/article/details/132659408
//4. std::visit 简介
//std::visit 是 C++17 中引入的一个工具，
// 用于访问和操作存储在 std::variant 类型中的数据。std::variant 是一种类型安全的联合体，可以存储固定集合中的任何类型，但在任何给定时间只能持有这些类型中的一个。

void variant_visit_main()
{
    std::variant<int,string, float> v;
    v = float(1.123);
    int i = std::get<float>(v);

    int index = v.index();
    cout << index << endl;

    // std::visit
    std::visit([](const auto &x)
    {
        using T = std::decay_t<decltype(x)>;
        if constexpr( std::is_same_v<T, int>)
            cout << "visiting int value "<< x << endl;
        else if constexpr(std::is_same_v<T,float>)
            cout << "visiting float " << x << endl;
        else if constexpr(std::is_same_v<T,string>)
            cout << "visiting string " << x << endl;
    }, v);


    // std::get_if
    if (auto p = std::get_if<float>(&v))
    {
        cout << *p << endl;
    }

    // std::holds_alternative
    if(std::holds_alternative<float>(v))
    {
        auto value = std::get<float>(v);
        cout << " float value : " << value << endl;
    }


    else if (std::holds_alternative<int>(v))
    {
        auto value = std::get<int>(v);
        cout << " int value : " << value << endl;
    }


    v = "sdfdsafa";
    if (std::holds_alternative<string>(v))
    {
        string value = std::get<string>(v);
        cout << " string value : " << value << endl;
    }

}

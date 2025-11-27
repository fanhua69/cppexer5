//
//  visit.cpp
//  testcpp3
//
//  Created by hua fan on 2024-02-24.
//

#include <stdio.h>
#include "headers.h"
#include <variant>

template<class... Ts>
struct overloaded : Ts...
{
    using Ts::operator()...;
};

template<class... Ts>
overloaded(Ts...)->overloaded<Ts...>;


struct mystruct
{
    int m;
    string s;
};

struct mystruct getStruct()
{
    return {1,"swrwer"};
}



void visit_main()
{
//    std::variant<double, int, string> value = 119;
//    std::visit(overloaded{
//                [](const double &v) { cout << v << endl;},
//                [](const int    &v) { cout << v << endl;}
//                }, value);
//
//
//    std::variant<int, std::string> v = "hello";
//  std::cout << "Index of currently stored value is " << v.index() << std::endl;
//  
//  if (std::holds_alternative<std::string>(v)) {
//    std::cout << "Currently stored value is a string." << std::endl;
//  }
//
//  if (value.index() == 1)
//    std::get<1>(value);
//    cout << endl;
////        cout << std::get<string> (value) << endl;

    map<int, string> m;
    m[1] = "adfwd";
    m[2] = "dsfasdfsdaf";


    for (auto [k, v]: m)
    {
        m[k] = "sadfdsaf323423";
        cout << k << ", " << v <<", " << m[k] << endl;
    }

    const auto &[a, b] = getStruct();
    cout << a << ", " << b <<endl;


}



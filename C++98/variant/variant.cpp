//
//  variant.cpp
//  testcpp2
//
//  Created by hua fan on 2023-08-10.
//

#include <stdio.h>
#include <variant>
#include "headers.h"

struct variantState
{
    variantState(int i): i(i){}
    int i;
};

void variantMain()
{
    std::variant<std::monostate, variantState> a;

    try
    {
        std::get<variantState>(a);
    }
    catch(const std::bad_variant_access& e)
    {
        std::cout << e.what() << '\n';
    }

    a=43;
    std::cout << "std::get :: " << std::get<variantState>(a).i << '\n';

    std::cout << "std::hash: " << std::hex << std::showbase
    << std::hash<std::monostate>{}(std::monostate{}) << '\n';


    std::variant<int, long,char> s;
    s=(long)65;

   // cout << std::dec << get<int>(s) << endl;
    cout << std::dec << get<long> (s) << endl;
    

}

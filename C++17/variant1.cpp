//
//  variant1.cpp
//  testcpp3
//
//  Created by hua fan on 2025-06-25.
//

#include "headers_2.h"
#include <iostream>
#include <variant>

using namespace std;
    
void variant1_main()
{
    std::variant<char, int,string> v;
    v = 'c';
    v = 12345;
    v = "aaaaa";
    
    if(std::holds_alternative<int>(v))
    {
        cout << "int:" << std::get<int>(v) << endl;
    }
    
    if(std::holds_alternative<string> (v))
    {
        cout << "string:" << std::get<string>(v) << endl;
    }
    
    cout << get<string>(v) << endl;
    cout << get<2> (v) << endl;
    
    std::visit([](auto &&arg) {cout << "visit:" << arg << endl;}, v);
    
    // Monostate:
    std::variant<std::monostate, int, float> v2;
    cout << v.index() << endl;
    cout << v2.index() << endl;
    
    
    // visitor:
    auto visitor = [](auto && arg)
    {
        using T = std::decay_t<decltype(arg)>;
        if constexpr (std::is_same_v<T,int>)
            cout << "in visitor int:" << arg << endl;
        
        else if constexpr(std::is_same_v<T, std::string>)
            cout << "in visitor string;" << arg << endl;
        
        else
            cout <<" not known type:"  << endl;
    };
    std::visit(visitor,v2);
    
    std::variant <int, std::string> v3;
    v3.emplace<std::string>(10,'x');
    cout << get<1> (v3) << endl;
    
    
    
}

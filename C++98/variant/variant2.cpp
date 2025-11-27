//
//  variant2.cpp
//  testcpp3
//
//  Created by hua fan on 2025-09-08.
//

#include "headers_2.h"
#include <iostream>
#include <variant>

using namespace std;
    
void variant2_main()
{
    std::variant <double, string> v2;
    v2 = 3.343;
    
    std::variant <double, string> v;
    v = 13.343;
    
    
    auto f = [](auto &&s, auto &&s2){
        cout << s << endl;
        cout << s2 << endl;
    };
    
    visit(f, v, v2);
    
}

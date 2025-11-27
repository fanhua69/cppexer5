//
//  variant22.cpp
//  testcpp3
//
//  Created by hua fan on 2025-10-24.
//




#include "headers_2.h"
#include <iostream>
#include <variant>

using namespace std;

void variant22_main()
{
    std::variant <int,string> v;
    v = "aaaa";
    v = 1234;
    
    try{
        int n = std::get<int>(v);
        cout << n << endl;
        int nn  = std::get<0>(v);
        cout << v.index() << endl;
        auto s= std::get<1>(v);
        
        
        std::visit([](auto && x){
            cout << x << endl;
        }, v);
    }
    catch (const std::bad_variant_access &e)
    {
        cout << "bad access variant" << endl;
        throw;
    }
    catch(...)
    {
        
    }
    
    
    
    
}

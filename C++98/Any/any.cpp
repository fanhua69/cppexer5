//
//  any.cpp
//  testcpp3
//
//  Created by hua fan on 2025-09-08.
//

#include "headers_2.h"
#include <iostream>
#include <any>

using namespace std;
    
void any_main()
{
    any a = 123;
    cout << any_cast<int>(a) << endl;
    
    if(int p = std::any_cast<int>(a))
    {
        cout << p << endl;
    }
    
    try {
        string s = std::any_cast<string>(a);
        cout << s << endl;
    } catch (const std::bad_any_cast & e) {
        std::cerr << "Type mismatch: " << e.what() << "\n";
    }
    a.reset();
    if(!a.has_value())
    {
        cout << "no value" << endl;
    }
    
    
}

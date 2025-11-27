//
//  any1.cpp
//  testcpp3
//
//  Created by hua fan on 2025-06-26.
//

#include "headers_2.h"
#include <iostream>
#include <any>

using namespace std;
    
void any1_main()
{
    std::any a = 123;
    cout << std::any_cast<int>(a) << endl;
    
    if(int *p = std::any_cast<int>(&a))
    {
        cout << *p << endl;
    }
    
    if(a.type() == typeid(int))
    {
        cout << "int " << std::any_cast<int>(a) << endl;
    }
    
    try {
        string s = any_cast<string>(a);
    }
    catch (const std::bad_any_cast& e)
    {
        std::cerr << "Type mismatch: " << e.what() << endl;
    }
    
    int n = 1234;
    
    int *p , p1;
    
    int& n2 = n, n3 = n;
    
    
    
    
    
    
}

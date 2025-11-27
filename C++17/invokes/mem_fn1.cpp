//
//  mem_fn1.cpp
//  testcpp3
//
//  Created by hua fan on 2025-11-11.
//


#include "headers_2.h"
#include <iostream>
#include <functional>

using namespace std;

namespace
{
class my_test
{
public:
    my_test(int x):m_x(x){};
    int add(int n){return m_x + n;}
    int m_x;
};
}
void mem_fn1_main()
{
    auto f = std::mem_fn(&my_test::add);
    auto d = my_test(111);
    cout << f(d, 1234) << endl;
    
    auto gx = std::mem_fn(&my_test::m_x);
    cout << gx(d) << endl;
    
    std::vector<my_test> v{1,2,3,4};
    for(auto vv : v)
    {
        cout << f(vv, 33) << endl;
    }
    
    
}

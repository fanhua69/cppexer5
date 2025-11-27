//
//  refwrapper.cpp
//  testcpp3
//
//  Created by hua fan on 2025-06-25.
//

#include "headers_2.h"
#include <iostream>
#include <functional>

using namespace std;

void test_func()
{
    cout << "in function" << endl;
    
}
    
void refwrapper_main()
{
    int a = 10;
    int &r = a;
    
    vector<int> v {r};
    cout << v[0] << endl;
    v[0] = 123;
    cout << a << endl; // a is not changed
    
    vector<std::reference_wrapper<int>> v2{ref(a)};
    v2[0].get() = 12134;
    cout << a << endl;  // a is changed

    std::reference_wrapper<int> r2(std::ref(r));
    r2.get() = 231432;
    cout << a << endl;
    
    int i = r2;
    cout << i << endl;
    
    std::reference_wrapper<void()> rf(test_func);
    rf();
    
    void (&rrr)() = rf;
    rrr();
    
    int a1=1, b1=2, c1=3;
    std::vector<reference_wrapper<int>> v1 ={a1,b1,c1};
    for (auto r : v1)
        r+=111;
    
    cout << a1 << ", " << b1 << " , " << c1 << endl;
    
    
    int a2 = 1220;
    reference_wrapper<int> r12(a2);
    
    int &ra2 = a2;
    reference_wrapper<int> r13(ra2);
    
    cout << r12 << endl;
    
    auto r21 = std::ref(a2);
    cout << typeid(r21).name() << endl;
    
    reference_wrapper<int> r22 = a2;
    
    
    
}

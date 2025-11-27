//
//  function_pointer.cpp
//  testcpp3
//
//  Created by hua fan on 2025-10-03.
//


#include "headers_2.h"
#include <iostream>
#include <functional>

using namespace std;

namespace {


class test
{
public:
    test(){
        cout << "test construcgor " << endl;
    }
    ~test()
    {
        cout << "test destructor" << endl;
    }
    
    
    void show(int n)
    {
        cout << n << endl;
    }
    
    int operator()(int a, int b){return a + b;}
};


}

void function_pointer_main()
{
    test b;
    test a = test();
    auto bf = std::bind(&test::show, &a, std::placeholders::_1);
    bf(123);
    

    std::function<int(int,int)> f = test{};
    
    auto f2 = f;
    
    cout << "Functor:" << f(1,2) << endl;
    cout << f2(3,5) << endl;

}

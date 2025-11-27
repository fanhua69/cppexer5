//
//  testhiding.cpp
//  testcpp3
//
//  Created by hua fan on 2025-11-10.
//

#include <iostream>
#include <variant>

using namespace std;

namespace
{
class Base
{
public:
    virtual void func() { cout << "Base" << endl;}
    void func(int a, int b, int c)
    {
        cout << "BASE 3 a" << endl;
    }
};

class Derived: public Base
{
public:
    int func(int a)
    {
        cout << "Derived" << endl;
        return 1;
    }
};

class Add
{
public:
    int operator()(int a, int b)
    {
        return a  + b;
    }
    
    int operator ()()
    {
        return 10;
    }
    
    double operator()(double d)
    {
        return d*2;
    }

};

}


#include "headers_2.h"
#include <iostream>
using namespace std;

void testhiding_main()
{
    Derived d;
    d.func(123);
    d.Base::func();
    d.Base::func(1,2,3);
    
    ((Base*)(&d))->func(1,2,3);
    Base * p = &d;
    p->func();
    p->func(1,2,4);
    

    
    Add a;
    cout << a(12,12) << endl;
    cout << a() << endl;
    
    std::variant<std::monostate, int, string> v;
    v = 134;
    if(auto p = std::get_if<int>(&v))
    {
        cout << *p << endl;
    }
}

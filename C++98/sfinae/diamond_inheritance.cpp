//
//  diamond_inheritance.cpp
//  testcpp3
//
//  Created by hua fan on 2025-10-26.
//


#include "headers_2.h"
#include <iostream>
#include <coroutine>

using namespace std;




namespace
{
class A { public: int x; };
class B : virtual public A {};
class C : public A {};
class D : public B, public C {};



}

void diamond_inheritance_main()
{
    D d;
    d.B::x = 10;
    d.C::x = 20;
    

    
    
    cout << d.B::x << ", " << d.C::x << endl;
}

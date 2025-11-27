//
//  functions.cpp
//  testcpp3
//
//  Created by hua fan on 2025-07-23.
//

#include "headers_2.h"
#include <iostream>
#include <functional>

using namespace std;

struct AddOne
{
    int operator()(int x) const
    {
        return x + 1;
    }
    
    int test(int x)
    {
        return x + 1;
    }
};

struct Foo
{
    Foo(int num) : num_(num)
    {}

    int add(int i) const
    {
        return num_+i;
    }
    int num_;
};
 


int addfunction(int x)
{
    return x + 2;
}
    
void functions_main()
{
    // 1 . lambda
    std::function<int(int)> f = [](int x ){return x + 1;};
    
    print(f(10));
    
    // 2. Function pointer:
    std::function<int(int)> f2 = addfunction;
    print(f2(11));
    
    // 3. functor:
    
    std::function<int(int)> f3 = AddOne();
    AddOne a;
    std::function<int(int)> f31 = a;
    print(a(123));
    
    // 4. Result of std::bind
    auto b = std::bind(addfunction, 133);
    print(b());
    print(b(231));
    
    
    std::function<int()> f4 = b;
    print(f4());
    
    // 5. class function with bind:
    AddOne o;
    std::function<int(int)> f5 = std::bind(&AddOne::test, o, std::placeholders::_1);
    print(f5(111));
    
    std::function<int(int)> f6 = std::bind(&AddOne::test, ref(o), std::placeholders::_1);
    print(f6(11));

    std::function<int(int)> f7 = std::bind(&AddOne::test, &o, std::placeholders::_1);
    print(f7(11));
    
    // 5.1 store a call to a member function
    std::function<int(const Foo&, int)> f71 = &Foo::add;
    const Foo foo(3);
    print(f71(foo, 1));
    print(f71(3, 1));
 

    

    // 6. Capture - less lambda as function pointer:
    auto l = [](int x){return x + 1;};
    int(*fp)(int) = l;
    print(fp(122));
    print((*fp)(122));
    std::function<int(int)> f8 = fp;
    print(f8(122));
    
    
    
    
}

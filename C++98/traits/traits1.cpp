//
//  traits1.cpp
//  testcpp3
//
//  Created by hua fan on 2025-06-26.
//

#include "headers_2.h"
#include <iostream>
#include <type_traits>

using namespace std;

class trait_class
{
    virtual void func() = 0;
};

class final_class final : public trait_class
{
    virtual void func() final;
};

class aggregate_class
{
public:
    int a;
    int b;
};
    
void traits1_main()
{
    // Value traits:
    cout << is_same_v<int, int> << endl;
    cout << is_same_v<int, float> << endl;
    cout << is_volatile<volatile int>::value << endl;
    cout << is_trivial<int>::value << endl;
    cout << is_trivially_copyable<int>::value << endl;
    cout << is_standard_layout_v<int> << endl;
    cout << is_pod<int>::value<< endl;
    cout << is_empty<int>::value<< endl;
    cout << is_empty<trait_class>::value << endl;
    cout << is_polymorphic<int>::value << endl;
    cout << is_abstract<trait_class>::value << endl;
    cout << "is final:" << is_final<final_class>::value << endl;
    cout << "is aggredate:" << is_aggregate<aggregate_class>::value << endl;
    
    cout << "is base of:" << is_base_of<trait_class, final_class>::value << endl;
    cout << "is convertible:" << is_convertible_v<float, int> << endl;
    cout << "is convertible:" << is_convertible<trait_class*, final_class*>::value << endl;

    cout << "is constructible:" << is_constructible<aggregate_class, int, int>::value << endl;
    
    cout << " is assignable : " << is_assignable<int&, int>::value << endl;
    cout << "is invocable: " << is_invocable<void()>::value << endl;
    cout << "is invocable r : " << is_invocable_r<void, void()>::value << endl;
    
}








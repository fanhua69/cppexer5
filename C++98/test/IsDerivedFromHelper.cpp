//
//  IsDerivedFromHelper.swift
//  testcpp3
//
//  Created by hua fan on 2024-10-25.
//



#include <iostream>

using namespace std;


template <class B, class A>
class IsDerivedFromHelper
{
    public:
        class No
        {
        };
        class Yes
        {
            No n[3];
        };

        static Yes test(A*) ;
        static No  test(...);

        enum
        {
            Is = sizeof(test(static_cast<B*>(0))) == sizeof(Yes)
        };
};

template <class B, class A>
bool IsDerivedFrom()
{
    return IsDerivedFromHelper<B, A>::Is;
}

class A
{};

class B : public A
{};

int ttttt(A*)
{
    return 9999;
}

int ttttt(string s, ...)
{
    cout << "string " << endl;
    return 0;
}

int ttttt(...)
{
    cout << " any arguments" << endl;
    return 1000;
}



namespace details
{
    template<typename B>
    std::true_type  test_ptr_conv(const volatile B*);
    template<typename>
    std::false_type test_ptr_conv(const volatile void*);
 
    template<typename B, typename D>
    auto test_is_base_of(int) -> decltype(test_ptr_conv<B>(static_cast<D*>(nullptr)));

    template<typename, typename>
    auto test_is_base_of(...) -> std::true_type; // private or ambiguous base
}
 
template<typename Base, typename Derived>
struct is_base_of :
    std::integral_constant<
        bool,
        std::is_class<Base>::value &&
        std::is_class<Derived>::value &&
        decltype(details::test_is_base_of<Base, Derived>(0))::value
    > {};


using namespace std;



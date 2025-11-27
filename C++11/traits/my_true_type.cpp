//
//  my_true_type.cpp
//  testcpp3
//
//  Created by hua fan on 2025-10-22.
//


#include "headers_2.h"
#include <iostream>
using namespace std;

struct my_true_type
{
    static constexpr bool value = true;
    using value_type = bool;
    using type = my_true_type;
    constexpr operator value_type() const noexcept
    {
        return value;
    }
};

struct my_false_type
{
    static constexpr bool value = false;
    using value_type = bool;
    using type = my_false_type;
    constexpr operator value_type () const noexcept
    {
        return value;
    }
};

template <typename T>
struct my_is_integral: std::false_type
{
};

template <>
struct my_is_integral<int>: std::true_type
{
};

template <>
struct my_is_integral<char>: std::true_type
{
};

template <typename T>
struct is_char : std::false_type
{};

template <>
struct is_char<char>: std::true_type
{};

template <typename T>
void process(T value)
{
    static_assert(std::is_integral<T>::value, "This has to be a integral");
}

template <bool B, typename T, typename F>
using choose = typename std::conditional<B, T, F>::type;

template <typename T>
using Vec = std::vector<T>;


template <bool B, typename T, typename F>
struct myconditional
{
    using type = F;
};

template <typename T, typename F>
struct myconditional<true, T, F>
{
    using type = T;
};

template <std::integral T>
void foo(T x)
{
    cout << "Integral :" << x << endl;
}





void my_true_type_main()
{
    cout << is_char <int>::value << endl;
    cout << is_char <char>::value << endl;
    static_assert(std::true_type::value, "This is true");
    static_assert(!std::false_type::value, "This is false");
    process(1);
    //process(1.1);
    using type1 = std::conditional<true, int, float>::type;
    type1 t = 13;
    cout << typeid(t).name() << endl;
    
    Vec<int> v;
    v.push_back(1);
    
    choose<true, int , float> a;
    std::conditional<true, int, float>::type b;
    
    

    
    
}

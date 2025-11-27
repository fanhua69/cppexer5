//
//  NCRTest.cpp
//  testcpp3
//
//  Created by hua fan on 2025-01-08.
//


#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <variant>
#include <array>
#include <any>
#include <ranges>
#include <print>
#include <chrono>
#include <list>

using namespace std;
using namespace std::chrono_literals;

class ParentClass
{
public:
    ParentClass(){};
    virtual void setData(int n) = 0;
    virtual ~ParentClass(){};
    virtual void show() {
        cout << "Parent Class " << endl;
    }

private:
    vector<int> m_data;
};

class Child: public virtual ParentClass
{
    public:
        using ParentClass::ParentClass;
        void setData(int n) override
        {};

        virtual ~Child(){};
        virtual void show() final
        {
            cout << "Child Class " << endl;
        }
};

void test(std::unique_ptr<Child> &p)
{
    cout << " in test " << endl;
}

template <typename ...Args>
void testTemplate(Args ...args)
{
    int n = ( args + ... );
    int m = ( 1 + ... + args);
    m = (... + args);
    m = (args + ... + 2);
    cout << m << ", " << n << endl;



    cout << n << endl;

    ((cout << args << ", " ), ...);
}

namespace std::ranges
{
    template<class T>
    concept range2 = requires(T t)
    {
        ranges::begin(t);
        ranges::end(t);
    };
};

template <typename T>
requires std::ranges::range2<T> && (sizeof(T) > 2)
void myrangeuse(const T &t)
{
    for(auto it = std::begin(t); it != std::end(t); ++it)
        cout << *it << endl;
}

template<typename T>
concept SupportsAddition = requires(T a, T b)
{
    a + b;
};

template<typename T>
requires SupportsAddition<T>
void addAndPrint(T a, T b)
{
    cout << "sum:" << a + b << endl;
}

template <typename T>
void vvvv(T a, T b)
{
    cout << a + b << endl;
}

template <typename T>
void func()
{
    typename T::value_type x;
}

using namespace std::chrono;

class TestIni
{
    int a;
    int b;
public:

    TestIni() : b(2), a(b)
    {
        cout << " a = " << a << ", b = " << b << endl;
        a = 20;
    }
};


template <typename T>
void TestT(T t)
{
    cout << t << endl;
}

template<typename T, typename ...Args>
void TestT(T t, Args ... args)
{
    cout << t << ", ";
    TestT(args...);
}

string trim(string s)
{
    stringstream ss(s);
    string v;
    ss >> v;
    return v;
}

void DemoMain()
{
    std::bitset<16> ss("00000000");
    std::bitset<16> ss2("00000100");

    ss |= ss2;
    cout << ss << endl;
    ss ^= ss2;
    cout << ss << endl;




}






#include "headers_2.h"
#include <iostream>
using namespace std;

void NCRTest_main()
{
}

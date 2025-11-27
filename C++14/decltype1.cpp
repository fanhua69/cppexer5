//
//  decltype1.cpp
//  testcpp3
//
//  Created by hua fan on 2025-09-05.
//

#include "headers_2.h"
#include <iostream>
#include <numeric>
#include <random>
#include <functional>
#include <iomanip>
#include <sstream>
#include <variant>
#include <optional>


using namespace std;

template<typename... Args>
void test(Args&&... args)
{
    (cout << ... << args) << endl;
    ((cout << args), ...);
}

class tt
{
public:
    tt(int x)
    {
        value = x;
    }
    
    friend ostream& operator << (ostream &os , const tt& obj)
    {
        os << obj.value;
        return os;
    }
    
    ostream & operator >> (ostream &os)
    {
        os << value ;
        return os;
    }
    
    int value;
};

auto tttt(auto i) ->decltype(i)
{
    return i * 123;
}

template <typename T>
T f(T x)
{
    return x  * 10;
}

//template <typename T>
//void func(T t)
//{
//    if(std::is_integral<T>::value)
//        t+1;
//    else
//        t.push_back(0);
//}

template <typename T>
void func2(T t)
{
    if constexpr(std::is_integral<T>::value)
        t+1;
    else
        t.push_back(0);
}

void decltype1_main()
{

    vector v = {1,2,3};
    vector <vector<int>> v2(10, vector<int>(10));
    std::vector v3(10, std::vector(10, 0));
    vector<vector<int>> v4;
    
    
    vector<int> a = {1,23,3};
    vector a1{1,2,3};
    pair p = {1,2};
    auto p2 = make_pair(1,3);
    
    func2(1);
    
    std::optional<int> t;
    t = nullopt;
    t.emplace(20);
    if(t.has_value())
        cout << "has value " << endl;
    else
        cout << "no value " << endl;
    
    if(t)
        cout << "has " << endl;
    else
        cout << " no " << endl;
    
    if (t == 20)
        cout << "20" << endl;
    else
        cout << "not 20" << endl;
    
    if (t.value() == 20)
        cout << "20000" << endl;
        
    
    if ( t!=nullopt)
        cout << "not nullopt" << endl;
    
    
}

//
//  coroutine3.cpp
//  testcpp3
//
//  Created by hua fan on 2025-10-09.
//


#include "headers_2.h"
#include <iostream>
#include <algorithm>

using namespace std;

string trim(string& s)
{
    const std::string white = " \t\n\r";
    const auto start = s.find_first_not_of(white);
    if(start == string::npos)
        return "";
    
    const auto end = s.find_last_not_of(white);
    
    cout << s.find_first_of(white) << endl;
    
    return s.substr(start, end - start + 1);
    
}

string ltrim(string &s)
{
    auto it = std::find_if(s.begin(), s.end(), [](unsigned char c) { return !std::isspace(c);});
    s.erase(s.begin(), it);
    return s;
}

string rtrim(string &s)
{
    auto it = std::find_if(s.rbegin(), s.rend(), [](char c){return std::isalnum(c);});
    s.erase(it.base(), s.end());
    return s;
}

template<typename T>
struct MyAllocator {
    using value_type = T;
    MyAllocator() noexcept
    {
        
    }
    
    template<typename U>
    MyAllocator(const MyAllocator<U> &)noexcept
    {
    }
    
    T* allocate(std::size_t n)
    {
        if(n == 0)
            return nullptr;
        
        T* p = static_cast<T*> (::operator new (n * sizeof(T)));
        return p;
    }
    
    void deallocate(T *p, std::size_t n)
    {
        cout << " deleing : " << n << endl;
        ::operator delete (p);
    }
    
    void show(){
        cout << m_data << endl;
    }
    int m_data = 1230;
};


int getlen()
{
    return 10;
}

void tp(int a, int b, string s)
{
    cout << a << b << s << endl;
}

template <typename T, typename ...Args>
void ppp(T t, Args ... args)
{
    cout << t << endl;
    if constexpr (sizeof...(args) > 0)
        ppp(args...);
}


template<typename T>
struct is_vector : std::false_type
{
    
};

template<typename T, typename A>
struct is_vector<std::vector<T, A>> : std::true_type
{
};

void coroutine3_main()
{
    vector<int> v;
    cout << is_vector<vector<int>>::value << endl;
    cout << is_vector<decltype(v)>::value <<endl;
 
    
}

//
//  truetype1.cpp
//  testcpp3
//
//  Created by hua fan on 2025-10-12.
//


#include "headers_2.h"
#include <iostream>
#include <type_traits>
#include <unordered_map>


using namespace std;

namespace {

//template<typename T>
//void check (T, std::true_type)
//{
//    cout << "Is Pointer\n"<< endl;
//}
//
//template<typename T>
//void check (T , std::false_type)
//{
//    cout << " Not a pointer type\n";
//}

//template<typename T>
//void check( T t,  bool b)
//{
//    if constexpr (b)
//        cout << "true" << endl;
//    else
//        cout << "false " << endl;
//}


template<typename T>
void check( T t)
{
    if constexpr (std::is_pointer_v<T>)
        cout << "true" << endl;
    else
        cout << "false" << endl;
}

string findMaxLen(const string &s)
{
    int left = 0;
    int start = 0;
    int maxlen = 0;
    unordered_map<char,int> m;
    for(int right = 0; right < s.length(); right++)
    {
        char c = s[right];
        m[c]++;
        while(m[c] > 1)
        {
            char cl = s[left];
            m[cl]--;
            if(m[cl] == 0)
            {
                m.erase(cl);
            }
            left++;
        }
        
        if(m.size()>maxlen)
        {
            maxlen = m.size();
            start = left;
        }
    }
    
    return s.substr(start, maxlen);
}

string findKlen(const string &s, int k)
{
    int left = 0;
    int right = 0;
    int maxlen = 1;
    int start = 0;
    
    std::unordered_map<char, int> m;
    for(int right = 0; right < s.length(); right ++)
    {
        m[s[right]]++;
        while(m.size()>k)
        {
            m[s[left]]--;
            if(m[s[left]] == 0)
            {
                m.erase(s[left]);
            }
            left++;
        }
        if(right-left + 1 > maxlen)
        {
            maxlen = right-left + 1;
            start = left;
        }
    }
    
    return s.substr(start, maxlen);
}

char combine(char a, char b)
{
    if(a==b)return a;
    if(a == 'a' && b == 'b' || a == 'b' && b == 'a') return 'c';
    if(a == 'b' && b == 'c' || a == 'c' && b == 'b') return 'a';
    if(a == 'a' && b == 'c' || a == 'c' && b == 'a') return 'b';
    return '?';
}

string shrink(const string &s)
{
    string st;
    for(auto c : s)
    {
        while(st.size() && st.back() != c)
        {
            char pc = st.back();
            st.pop_back();
            c = combine(pc, c);
        }
        st.push_back(c);
    }
    return st;
}

}

void truetype1_main()
{
    cout << shrink("ababababc") << endl;
}

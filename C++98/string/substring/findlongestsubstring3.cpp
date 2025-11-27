//
//  findlongestsubstring3.cpp
//  testcpp3
//
//  Created by hua fan on 2025-07-01.
//

#include "headers_2.h"
#include <iostream>
using namespace std;
    

string findLongestSubstring3(std::string_view s)
{
    set<char> sf;
    size_t start = 0;
    string ss = "";
    string ms = "";
    for(int i = 0; i < s.size(); i++)
    {
        if(sf.contains(s[i]))
        {
            size_t p = s.find_first_of(s[i], start);
            ss = s.substr(p + 1, i - p);
            ms = ms.size() > ss.size() ? ms:ss;
            start = p + 1;
            sf.clear();
            sf.insert(ss.begin(), ss.end());
        }
        else
        {
            sf.insert(s[i]);
            ss+=s[i];
        }
    }
    
    ms = ms.size() > ss.size() ? ms:ss;
    return ms;
    
}

string_view findLongestSubString4(const string_view &s)
{
    set<char> seen;
    size_t start = 0;
    string res;
    size_t ml = 0;
    size_t ms = 0;
    for(int i = 0; i < s.size(); i ++)
    {
        while(seen.contains(s[i]))
        {
            seen.erase(s[start++]);
        }
        seen.insert(s[i]);
        
        if( i - start + 1 > res.size())
        {
            ms = start;
            ml = i - start + 1;
        }
    }
    return s.substr(ms, ml);
}

void findlongestsubstring3_main()
{
    string s = "abcdeabcdefg";
    cout << findLongestSubstring3(string_view(s)) << endl;
    cout << string(findLongestSubString4(string_view(s))) << endl;
    
}

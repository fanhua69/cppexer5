//
//  findLongestSubstring.cpp
//  testcpp3
//
//  Created by hua fan on 2024-11-23.
//


#include <string>
#include <vector>
#include <set>

using namespace std;


string longestSubString;

auto updateString = [](auto b, auto e){ string s(b,e); if (s.length() > longestSubString.length()) longestSubString = s;};



string findLongestSubString(string &s)
{

    set<std::string::value_type> uniqueChars;

    auto b = s.begin();
    auto e = b;

    while ( e != s.end())
    {
        if(uniqueChars.count(*e) == 0)
        {
            uniqueChars.insert(*e);
            updateString(b,e);
            e++;
        }
        else
        {
            uniqueChars.erase(*b);
            b++;
        }
    }

    return string(b,e);

}

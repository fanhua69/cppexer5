//
//  find_longest_substr.cpp
//  testcpp3
//
//  Created by hua fan on 2025-10-30.
//


#include "headers_2.h"
#include <iostream>
using namespace std;


size_t find_longest_substr(const string &s1)
{
    std::map<char,int> m;
    size_t ml = 0;
    size_t left = 0, right = 0;
    while(right < s1.size())
    {
        char c = s1[right];
        while(m[c]>0)
        {
            char cl = s1[left++];
            m[cl]--;
            if(m[cl] == 0)
            {
                m.erase(cl);
            }
        }
        
        m[c]++;
        right++;
        ml = max(ml, right - left);
    }
    
    return ml;
}

void find_longest_substr_main()
{
    cout << find_longest_substr("abcbcdefgabc") << endl;
}

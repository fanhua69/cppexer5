//
//  findSubString.cpp
//  testcpp2
//
//  Created by hua fan on 2023-08-10.
//

#include <stdio.h>
#include "headers.h"
#include <unordered_set>


string findLongestSubString(const string &s)
{
    int longestStart = 0;
    int longestEnd   = 0;

    int currentStart = 0;
    int currentEnd   = 0;
    std::map<char, int> pos;

    for(int i = 0; i < s.size(); ++i)
    {
        const char c = s[i];
        if( pos.count(c) == 0)
        {
            pos[c] = i;
        }
        else
        {
            currentEnd = i - 1;

            if(currentEnd - currentStart + 1 > longestEnd - longestStart + 1)
            {
                longestStart = currentStart;
                longestEnd   = currentEnd;
            }

            currentStart = pos[c] + 1;
            pos.clear();
            for(int j = currentStart; j <= currentEnd; j++)
            {
                pos[s[j]] = j;
            }
        }
    }

    currentEnd = s.size() - 1;
    if (currentEnd - currentStart + 1 > longestEnd - longestStart + 1)
    {
        longestStart = currentStart;
        longestEnd   = currentEnd;
    }

    return s.substr(longestStart, longestEnd - longestStart + 1);
}

void findLongestSubstringMain()
{
    string s = "12312345";
    cout << findLongestSubString(s) << endl;

    s = "121345";
    cout << findLongestSubString(s) << endl;

    s = "4556789";
    cout << findLongestSubString(s) << endl;

    s = "556789";
    cout << findLongestSubString(s) << endl;

    s = "45675678989";
    cout << findLongestSubString(s) << endl;

    s = "56789";
    cout << findLongestSubString(s) << endl;

}

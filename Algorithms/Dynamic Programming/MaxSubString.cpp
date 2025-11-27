//
//  MaxSubString.cpp
//  testcpp2
//
//  Created by hua fan on 2023-09-30.
//

#include <stdio.h>
#include "headers.h"
#include <algorithm>


int findLongestSubString(string s)
{
    set<char> ec;
    map<char, int> mc;

    size_t ml = 0;

    for(int i = 0; i< s.size(); i++)
    {
        char c = s[i];

        if(ec.count(c) > 0)
        {
            int start = mc[c]+1;
            ec.clear();
            mc.clear();
            for(int j = start; j < i; j ++)
            {
                ec.insert(s[j]);
                mc[s[j]] = j;
            }
        }

        ec.insert(c);
        mc[c] = i;

        ml = max(ml, ec.size());
    }

    return ml;
}


void MaxSubStringMain()
{
    cout << findLongestSubString("abcdecfgh") << endl;
}

//
//  compare_ocr1.cpp
//  testcpp3
//
//  Created by hua fan on 2025-10-30.
//


#include "headers_2.h"
#include <iostream>
using namespace std;


void expand_ocr(const string &s, size_t pos, string &se)
{
    if(pos >= s.size())
        return ;
    
    while(pos < s.size() && std::isalpha(s[pos]))
    {
        se += s[pos++];
    }
    
    string ns;
    while(pos < s.size() && isdigit(s[pos]))
    {
        ns+=s[pos++];
    }
    
    if(ns.size() > 0)
    {
        se+=string(stoi(ns),'?');
    }
    
    expand_ocr(s, pos, se);
}

bool compare_ocr(const string &s1, const string &s2)
{
    string se1, se2;
    expand_ocr(s1,0,se1);
    expand_ocr(s2,0,se2);
    
    cout << se1 << endl;
    cout << se2 << endl;
    
    if(se1.size() != se2.size())
        return false;
    
    for(int i = 0; i < se1.size(); ++i)
    {
        if(se1[i]=='?' || se2[i] == '?')
            continue;
        if(se1[i] != se2[i])
            return false;
        
    }
    return true;
}

void compare_ocr1_main()
{
    cout << compare_ocr("20A","10S9A") << endl;
}

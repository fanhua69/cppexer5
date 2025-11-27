//
//  compare_ocr.cpp
//  testcpp3
//
//  Created by hua fan on 2025-10-29.
//


#include "headers_2.h"
#include <iostream>
#include <cctype>
using namespace std;



// Helper: read a number starting at s[pos], update pos to the next char after the number
int readNumber(const string &s, size_t &pos)
{
    int num = 0;
    while (pos < s.size() && isdigit(s[pos])) {
        num = num * 10 + (s[pos] - '0');
        ++pos;
    }
    return num;
}// 判断是否是“压缩格式”：形如 A3B2C，特点是中间有数字

void addhead(string &s, size_t &pos, int n)
{
    string sn = to_string(n);
    size_t l = sn.length();
    for(int i = 0; i < l; ++i)
    {
        s[pos - l + i] = sn[i];
    }
    pos = pos - l;
}

bool check (string &s1, size_t pos1, string &s2, size_t pos2)
{
    if(pos1>=s1.size() && pos2 >= s2.size())
        return true;
    
    else if (pos1 >= s1.size() || pos2 >= s2.size())
        return false;
    
    if(isalpha(s1[pos1]) && isalpha(s2[pos2]))
    {
        if(s1[pos1] != s2[pos2])return false;
        return check(s1,pos1+1,s2,pos2+1);
    }
    
    if(isdigit(s1[pos1]) && isdigit(s2[pos2]))
    {
        int n1 = readNumber(s1, pos1);
        int n2 = readNumber(s2, pos2);
        if(n1 < n2)
        {
            n2-=n1;
            addhead(s2, pos2, n2);
            return check(s1, pos1, s2, pos2);
        }
        else if(n2 < n1)
        {
            n1-=n2;
            addhead(s1, pos1, n1);
            return check(s1, pos1, s2, pos2);
        }
        else
        {
            return check (s1, pos1, s2, pos2);
        }
    }
    
    if(isdigit(s1[pos1]) && !isdigit(s2[pos2]))
    {
        int n1 = readNumber(s1, pos1);
        addhead(s1, pos1, n1-1);
        return check(s1, pos1, s2, pos2+1);
    }
    
    if(!isdigit(s1[pos1]) && isdigit(s2[pos2]))
    {
        int n2 = readNumber(s2, pos2);
        addhead(s2, pos2, n2-1);
        return check(s1, pos1+1, s2, pos2);
    }
    
    return true;
}


int readNumber2(const string &s, size_t &pos)
{
    int num = 0;
    while(pos < s.size() && isdigit(s[pos]))
    {
        num = num * 10 + s[pos++] - '0';
    }
    return num;
}

bool matchStrings2(const string&s1, const string &s2)
{
    size_t p1 = 0;
    size_t p2 = 0;
    
    size_t rest1 = 0;
    size_t rest2 = 0;
    
    while(p1 < s1.size() || p2 < s2.size())
    {
        if(p1 < s1.size() && isdigit(s1[p1]))
        {
            rest1 = readNumber2(s1, p1);
        }
        
        if(p2 < s2.size() && isdigit(s2[p2]))
        {
            rest2 = readNumber2(s2, p2);
        }
        
        if(rest1 > rest2)
        {
            rest1 -= rest2;
            rest2 = 0;
        }
        else if (rest2 > rest1)
        {
            rest2 -= rest1;
            rest1 = 0;
        }
        else
        {
            rest2 = rest1 = 0;
        }
        
        while(rest1 > 0 && p2 < s2.size() && isalpha(s2[p2]))
        {
            rest1--;
            p2++;
        }
        
        while( rest2 > 0 && p1 < s1.size() && isalpha(s1[p1]))
        {
            rest2--;
            p1++;
        }
        
        if(rest1 == 0 && rest2 == 0)
        {
            if(s1[p1] != s2[p2])
            {
                return false;
            }
            else
            {
                p1++;
                p2++;
            }
        }
        
        if(p1 == s1.size() && rest2 > 0 || p2 == s2.size() && rest1 > 0)
            return false;
    }
    
    return rest1 == rest2;
}


void compare_ocr_main()
{
    cout << boolalpha;
    cout << matchStrings2("A2C", "3C") << endl;      // true
    cout << matchStrings2("A20C", "A5C") << endl; // false (different total length)
    cout << matchStrings2("A20C", "A18CC") << endl;  // false
    cout << matchStrings2("A20C", "A20C") << endl;   // true
    cout << matchStrings2("A20C", "A20C") << endl; // true
    cout << matchStrings2("A20C", "A9D10C") << endl; // true
    cout << matchStrings2("20D10C", "10A9D10C") << endl; // true
    cout << matchStrings2("20", "10A9") << endl; // true
    cout << matchStrings2("20Z", "10A9E") << endl; // false
    cout << matchStrings2("20", "10") << endl; // false
    
    
    
    

}

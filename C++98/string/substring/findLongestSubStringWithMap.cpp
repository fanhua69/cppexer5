//
//  findLongestSubStringWithMap.cpp
//  testcpp2
//
//  Created by hua fan on 2023-08-10.
//

#include <stdio.h>
#include "headers.h"


#include <string>
#include <unordered_map>
using namespace std;

//////////////////////////////////////////////////////////////////
// Find the longest substring without any duplicated characters:
//////////////////////////////////////////////////////////////////
string findLongestSubstring2(const string &s)
{
    string result;
    unordered_map<char,int> longestMap;
    int start = 0;
    for(int i =0; i < s.size(); ++i)
    {
        char c=s[i];

        if(longestMap.count(c) != 0)
        {
            if(longestMap.size() > result.size())
            {
                result = s.substr(start, longestMap.size());
            }

            int preStart = start;
            start = longestMap[c] + 1;
            for (int j = preStart; j < start; j++)
            {
                longestMap.erase(s[j]);
            }
        }
        longestMap[c] = i;
    }

    if(longestMap.size() > result.size())
    {
        result = s.substr(start, longestMap.size());
    }

    return result;
}

string findLongestSubstring(const string &s)
{
    string re;

    string::const_iterator b = s.begin();
    string::const_iterator e = s.begin();
    unordered_set<char> us;

    while(e!=s.end())
    {
        if (us.contains(*e))
        {
            string ms (b, e);
            if (ms.length() > re.length())
            {
                re = ms;
            }
            us.erase(*b);
            b++;
        }
        else
        {
            us.insert(*e);
            e++;
        }
    }

    string ms(b,e);
    if(ms.length() > re.length())
        re = ms;



    return re;
}

void printResult(string inputString, string answer)
{

    cout << endl;
    cout << "===============================================\n";
    string yourAnswer = findLongestSubstring(inputString);
    cout << "Input String: [" << inputString << "]" << endl;
    cout << "Right Answer: [" << answer      << "]" << endl;
    cout << "Your  Answer: [" << yourAnswer  << "]" ;
    cout << (yourAnswer == answer ? " Right" : " Wrong") << endl;
    cout << "===============================================\n";
    cout << endl;
}

///
void test0()
{
    printResult("", "");
}

void test1()
{
    printResult("abcde", "abcde");
}

void test2()
{
    printResult("abcdeabc", "abcde");
}

void test3()
{
    printResult("abcabcdeab", "abcde");
}

void test4()
{
    printResult("abcbdef", "cbdef");
}

void test5()
{
    printResult("abcdebafg", "cdebafg");
}


void findLongestSubStringWithMapMain()
{
    cout << "--------------------------------------------------------\n";
    test0();
    test1();
    test2();
    test3();
    test4();
    test5();
}

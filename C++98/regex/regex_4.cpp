//
//  regex_4.cpp
//  testcpp3
//
//  Created by hua fan on 2024-02-04.
//

#include <stdio.h>
#include "headers.h"
#include <regex>
#include <array>

namespace regex
{

void regex_4_main()
{
    vector<string> ss = {"abc.bash_ttt", "bash.abd"};

    std::regex m("[a-z.]{0,}(bash)([._a-z]{0,})");

    //for (auto s : ss)
      //  cout << s << ":" << std::regex_match(s, m) << endl;


    std::smatch m2;
    for(auto s: ss)
    {
        std::regex_match(s, m2, m);
        cout << s << " : m2 size = " << m2.size();
        for(int i =0 ; i < m2.size(); i++)
        {
            cout << " , i = "  << i << ", str: " << m2[i].str();
        }
        cout << endl;
    }
//}

//void regex_5_main()
//{
    std::string fnames[] = {"foo.txt", "bar.txt", "test", "a0.txt", "AAA.txt"};
    std::regex base_regex("([a-z]+)\\.txt");
    std::smatch base_match;
    for(const auto& fname: fnames) {
        if(std::regex_match(fname, base_match, base_regex))
        {
            // std::smatch 的第一个元素匹配整个字符串
            // std::smatch 的第二个元素匹配了第一个括号表达式
            if(base_match.size() == 2)
            {
                std::string base = base_match[1].str();
                std::cout << "sub-match[0]: "<< base_match[0].str() << std::endl;
                std::cout << fname << " sub-match[1]: "<< base << std::endl;
            }
        }
    }
   }

    void regex_6_main()
    {
        std::array dd = {"Windows2000", "Windows98", "Windows...."};
        std::regex re("Windows(?:98)");
        for(auto s : dd)
        {
            cout << s << ", match : " << std::regex_match(s, re) << endl;
        }
    }




}


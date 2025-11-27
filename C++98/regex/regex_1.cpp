//
//  regex_1.cpp
//  testcpp3
//
//  Created by hua fan on 2024-02-03.
//

#include <stdio.h>

#include "headers.h"
#include <regex>

namespace regex
{

    void regex_1_main()
    {
        std::string fnames[] = {"aaa*txt", ".txt", "foo.txt", "bar.txt", "test", "a0.txt", "AAA.txt"};

        std::regex txt_regex("[a-z]{1,}\\.txt");

        for (const auto &fname  : fnames)
            cout << fname << " : " << std::regex_match(fname, txt_regex) << std::endl;

    }

    void regex_2_main()
    {
        std::string fnames[] = {"aaa*txt", ".txt", "foo.txt", "bar.txt", "adsafds.txt", "test", "a0.txt", "AAA.txt"};
        std::regex base_regex("([a-z]+)\\.(txt)");
        std::smatch base_match;
        for(const auto &fname : fnames)
        {
            cout << fname  << endl;
            if(std::regex_match(fname, base_match, base_regex))
            {
                // std::smatch 的第一个元素匹配整个字符串
                // std::smatch 的第二个元素匹配了第一个括号表达式
                if(base_match.size() == 3)
                {
                    cout << fname << " : " ;
                    cout << base_match[0].str();
                    cout << ", base_match 1: " << base_match[1].str();
                    cout << ", base_match 2: " << base_match[2].str() << endl;
                }
            }
        }
        
        std::regex s1("[a-z]");
        if(std::regex_match("a", s1))
            cout << "yes" << endl;
        
        
    }

}

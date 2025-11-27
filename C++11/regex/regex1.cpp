//
//  regex1.cpp
//  testcpp3
//
//  Created by hua fan on 2025-10-01.
//


#include "headers_2.h"
#include <iostream>
#include <regex>
#include <iterator>


using namespace std;

void regex1_main()
{
    const std::string text = "C++11, C++14, C++17";
    std::regex cpp_version_regex ("C\\+\\+\\d+");
    auto begin = std::sregex_iterator(text.begin(), text.end(), cpp_version_regex);
    auto end = std::sregex_iterator();
    cout << "all : " << std::distance(begin, end) << endl;

    for(std::sregex_iterator it = begin ; it != end; ++it)
    {
        std::smatch m = *it;
        std::string ms = m.str();
        cout << ms << endl;
    }
    
    cout << "all : " << std::distance(begin, end) << endl;
    
    
    
}

//
//  quoted.cpp
//  testcpp3
//
//  Created by hua fan on 2024-04-01.
//

#include <stdio.h>

#include <iomanip>
#include <iostream>
#include <sstream>
#include "headers.h"

void default_delimiter()
{
    const std::string in = "std::quoted() quotes this string and embedded \"quotes\" too";
    std::stringstream ss;
    ss << std::quoted(in);
    std::string out;
    ss >> std::quoted(out);
 
    std::cout << "Default delimiter case:\n"
                 "read in     [" << in << "]\n"
                 "stored as   [" << ss.str() << "]\n"
                 "written out [" << out << "]\n\n";
}
 
void custom_delimiter()
{
    const char delim{'$'};
    const char escape{'%'};
 
    const std::string in = "std::quoted() quotes this string and embedded $quotes$ $too";
    std::stringstream ss;
    ss << std::quoted(in, delim, escape);
    std::string out;
    ss >> std::quoted(out, delim, escape);
 
    std::cout << "Custom delimiter case:\n"
                 "read in     [" << in << "]\n"
                 "stored as   [" << ss.str() << "]\n"
                 "written out [" << out << "]\n\n";
}
 
void quoted_main_2()
{
default_delimiter();
custom_delimiter();
}

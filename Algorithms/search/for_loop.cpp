//
//  for_loop.cpp
//  testcpp3
//
//  Created by hua fan on 2024-02-09.
//

#include <stdio.h>
#include "headers.h"
#include <mutex>

struct Employee
{
    Employee(std::string id) : id(id) {}
    std::string id;
    std::vector<std::string> lunch_partners;

    std::mutex m;
    std::string output() const
    {
        std::string ret = "Employee " + id + " has lunch partners: ";
        for(auto n {lunch_partners.size()}; const auto &partner : lunch_partners)
            ret += partner + (--n ? ", " : "");
        return ret;
    }
};

#include "headers_2.h"
#include <iostream>
using namespace std;

void for_loop2_main()
{
}

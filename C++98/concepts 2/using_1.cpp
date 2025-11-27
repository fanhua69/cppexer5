//
//  using_1.cpp
//  testcpp3
//
//  Created by hua fan on 2024-02-17.
//

#include <stdio.h>
#include "headers.h"

// https://www.xinbaoku.com/archive/6yaDu1ad.html

typedef unsigned int uint_t;

void func(unsigned int a)
{

}
//void func(uint_t a)
//{
//    print(a);
//}

typedef std::map<std::string, int> map_int_t;
typedef std::map<std::string, string> map_s_t;

template <typename Val>
struct str_map
{
    typedef std::map<std::string, Val> type;
};


template <typename Val>
using str_map_t = std::map<string, Val>;

using uint_t_u = unsigned int ;
using map_int_tt = std::map<string,int>;

void using_1_main()
{
    uint_t a;
    a = -1;
    cout << a << endl;

    str_map<int>::type map1;
    str_map_t<int> mm;
    mm["12"]=111;
    cout << mm["12"] << endl;


}

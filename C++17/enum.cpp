//
//  enum.cpp
//  testcpp3
//
//  Created by hua fan on 2024-02-24.
//

#include <stdio.h>
#include "headers.h"
#include <variant>

enum MyEnum : char
{
    value = 1,
    value2 = 2,
    value3 = 3
};


enum class MyEnum2: char
{
    value = 1,
    value2 = 2,
    value3 = 3
};


MyEnum me{3};

void enum_main()
{
    MyEnum2 m;
    m = MyEnum2::value2;
    cout << me << endl;
    cout << "m:" << (int)me << endl;

    if (me == value3)
    {
        cout << "qqqwer " << endl;
    }

    float v = 0x1f;
    cout << v << endl;

    std::map<int,int> tmp;
    if(tmp.contains(0))
    {
        cout << tmp[0] << endl;
    }
    else
    {
        cout << "no con" << endl;
    }


    std::set<int> n;
    n.contains(1);

    std::variant<int, float,string> v2;
    v2 = "fdafsadf";
    v2 = 1234.12f;
    cout << "index:" << v2.index() << endl;
    cout << get<float> (v2) << endl;
}




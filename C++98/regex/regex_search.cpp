//
//  regex_search.cpp
//  testcpp3
//
//  Created by hua fan on 2024-02-11.
//

#include <stdio.h>
#include "headers.h"
#include <regex>

namespace regex
{

struct testOrder
{
//    testOrder() {};
    virtual void testv(){};
    void test(){print("sdafsdf");};
    static int i;
};

int testOrder::i = 10;


void tttt( auto a)
{
    cout << a << endl;
}
void regex_search_main()
{
    std::string s = "I know, I'll use2 regular expressions.";

    std::regex self_regex("REGULAR EXPRESSIONS",  std::regex_constants::icase);
    if (std::regex_search(s, self_regex))
    {
        cout << "Text contains " << endl;
    }
    else
    {
        cout << "not found" << endl;
        print("not fouen");
    }

    std::shared_ptr<testOrder> p = make_shared<testOrder>();
    testOrder aa ;
    p->test();

    const int a = 10;
    const int &b = a;
    auto c = &a;
    cout << typeid(c).name() << endl;

    tttt(10.1);
    tttt("sdfs");


}

}

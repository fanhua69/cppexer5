//
//  optional.cpp
//  testcpp3
//
//  Created by hua fan on 2025-06-25.
//

#include "headers_2.h"
#include <iostream>
#include <optional>
#include <functional>

using namespace std;

struct person
{
    string name;
    optional<string> nickname;
};

std::optional<int> find(int n)
{
    if(n == 55)
        return n;
    return std::nullopt;
}
    
void optional_main()
{
    std::optional<int> o;
    o = std::nullopt;
    o.reset();
    o.emplace(13);
    
    std::optional<string> c{std::nullopt};
    c.emplace("abced");
    
    try
    {
        cout << o.value() << endl;
    }
    catch(std::exception &e)
    {
        cout << e.what() << endl;
        cout << " no value " << endl;
    }
    
    if(c)
    {
        cout << *c << endl;
    }
    
    std::optional <int> o2 {123};
    o2 == o;
    
    cout << (o2 > o) << endl;
    
    cout << (o == nullopt) << endl;
    
    auto n = find(55);
    if(n)
    {
        cout << "found : " << *n << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
    
    
    person p;
    p.name = "david";
    p.nickname = "nickname";
    if(p.nickname)
    {
        cout << *p.nickname << endl;
    }
    
    optional<int> a = 123;
    std::optional<int> b2 = std::move(a);
    if(a)
    {
        cout << "a has value after move : " <<  *a << endl;
    }
    else
    {
        cout << "no value " << endl;
    }
    
    
    optional <string> b = "assss";
    optional <string> b3 = std::move(b);
    if(b)
    {
        cout << " b has value after moved: " << *b << endl;
    }
    else
    {
        cout << " b has NO value after moved " << endl;
    }
    
    // Optional with reference:
    std::string s = "Hello";
    std::optional <std::reference_wrapper<std::string>> optRef = s;
    if(optRef)
    {
        cout << "referecne value : " << optRef->get() << endl;
        optRef->get() = "World";
        cout << "Original string after changing reference:" << s << endl;
    }
    
    
    //
    int c1 = 20;
    int &cr = c1;
    // optional<int&> ocr = cr;  // not allowed
    // cout << "ocr:" << *ocr << endl;
    
    optional <person> vv3{"sdf"};
    cout << (*vv3).name << endl;
    cout << vv3->name << endl;
    if(vv3->nickname)
        cout << vv3->nickname.value() << endl;
    
    // optional<void> aaa; invalid
    // optional<int[1]> bbb; invalid
    // optional<int &> ccc; invalid
}

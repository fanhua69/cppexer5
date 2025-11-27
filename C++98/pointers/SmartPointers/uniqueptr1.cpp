//
//  uniqueptr1.cpp
//  testcpp2
//
//  Created by hua fan on 2023-11-12.
//

#include <stdio.h>
#include "headers.h"
#include <memory>
#include <list>
#include <sstream>
#include <regex>
#include "math.h"
#include <iomanip>
#include <bitset>
#include <cassert>
#include <cstddef>
#include <iostream>
#include <memory>
#include <stdlib.h>


class A
{
    public:
    A() { cout << "a c " << endl;}
    ~A(){ cout << " a d " << endl;}

};

class B: public A
{
public:
    B() { cout << " b c " << endl;}
    ~B() { cout << " b d " << endl;}
    B(string s)
    {
        p = new char [s.length()  + 1];
        memcpy(p, s.data(), s.length()+1);
    }

//    B ( const  B & b)
//    {
//       p = new char [strlen(b.p)  + 1];
//        memcpy(p, b.p, strlen(b.p));
//        p[strlen(b.p)] = 0;
//    }
//
//        B ( const  B && b)
//    {
//       p = new char [strlen(b.p)  + 1];
//        memcpy(p, b.p, strlen(b.p));
//        p[strlen(b.p)] = 0;
//    }

//    B& operator = ( B & rhv)
//    {
//        if(p)
//            delete p;
//
//        p = rhv.p;
//        rhv.p = nullptr;
//        return *this;
//    }
//
//    B & operator = ( B && rhv)
//    {
//        if(p)
//        {
//            delete p;
//        }
//        p = rhv.p;
//        rhv.p = nullptr;
//        return * this;
//    }

    char * p = nullptr;
};

    ostream & operator << (ostream &out, B &b)
    {
        if(b.p)
        {
        for(int i = 0; i< strlen(b.p); i++)
            out << b.p[i];
            }
        return out;
    }

B getb()
{
    return B("test get b");
}

#include <queue>

void uniquePointerMain()
{

    string  *p = (string*)malloc(sizeof(string)*10);

    for(int i=0;i<10;i++)
    {
        new (p + i) string("sfsdf" + to_string(i)) ;
    }


    for(int i = 0; i< 10; i++)
    {
        cout << *(p + i) << endl;
    }

    for(int i=0;i<10;i++)
    {
        (p+i)->~string();
    }

    free(p);


    std::unique_ptr<int> p1 = std::make_unique<int>(10);
    cout << *p1 << endl;

    std::unique_ptr<int> p2 = std::move(p1);
//    cout << *p1 << endl; // crash
    cout << *p2 << endl;
}

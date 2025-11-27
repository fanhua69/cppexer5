//
//  inlinevariable.cpp
//  testcpp3
//
//  Created by hua fan on 2025-09-23.
//


#include "headers_2.h"
#include <iostream>
#include <algorithm>
#include <functional>
#include <ostream>

using namespace std;

namespace
{

class test
{
public:
    explicit test(int n )
    {
        m_data = n;
    }

    friend inline ostream & operator << (ostream &o, const test&t)
    {
        return o;
    }
    friend inline void ttt(test& a)
    {}
    

protected:
    
    int m_data;

};

void foo()
{
    class tt
    {
    public:
        void hello()
        {
            cout << "heelo " << endl;
        };
    };
    
    tt t;
    t.hello();
    
}


}

void inlinevariable_main()
{
    test t(123);
    
    cout << t << endl;
    ttt(t);
    
    foo();

}

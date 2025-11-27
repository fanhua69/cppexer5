//
//  copy_constructor.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-04.
//

#include <stdio.h>
#include "headers.h"

class X
{
public:
    X()
    {
        m_value =123;
    }

    X(int a = 11)
    {
        m_value = a;
    }

    X(const X& a)
    {
        m_value = a.m_value;
    }

    X& operator = (const X& rhs)
    {
        m_value = rhs.m_value;
        return *this;
    }

    X& operator = (X&& rhs)
    {
        m_value = rhs.m_value;
        return *this;
    }


    int getValue() const
    {
        return m_value;
    }

    friend ostream &operator << (ostream &os, const X &d);

private:
    int m_value;
};


ostream& operator << (ostream& s, const X& x)
{
    s << x.m_value;
    return s;
}

void copy_constructor_main()
{
    X a(123334);
    X b = a;
    b = a;

    b = std::move(a);

    std::cout << b << std::endl;

}

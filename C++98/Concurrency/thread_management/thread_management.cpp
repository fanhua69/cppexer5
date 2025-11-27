//
//  thread_management.cpp
//  testcpp3
//
//  Created by hua fan on 2024-11-14.
//

#include <thread>
#include <iostream>
#include <future>
#include <chrono>

using namespace std;

class Rational
{
    public:
        Rational() = default;
        Rational(int a = 2, int b = 3)
        {
            m_a = a;
            m_b = b;
        }

        int m_a;
        int m_b;
};


Rational operator *(const Rational &a, const Rational &b)
{
    return Rational(a.m_a * b.m_a , a.m_b * b.m_b);
}


class AAA
{
public:
    virtual void w(){ cout << "aaa" << endl;};
};

class BBB
{
public:
    virtual void w(){ cout << "bbb" << endl;};

};

class CCC: public BBB  , AAA
{
public:
    void we()
    {
        BBB::w();
    }

};


void thread_management_main()
{

    CCC c;
    c.we();


}

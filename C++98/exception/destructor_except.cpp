//
//  destructor_except.cpp
//  testcpp3
//
//  Created by hua fan on 2024-11-14.
//
#include <iostream>
#include <string>

using namespace std;

class dog2
{
    public:
        string m_name;
        dog2(string name)
        {
            m_name = name;
        }

        ~dog2() noexcept(false)
        {
            cout << "Dog : " << m_name << " is destructed" << endl;
            throw 20;
        }
};


void destructor_except_main()
{
    try {
        dog2 g1("dog 1");
        dog2 d2("dog 2");
    }
    catch (int e)
    {
        cout << e << " is caught" << endl;
    }
    catch (...)
    {

    }
}

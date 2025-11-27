//
//  shared_ptr.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-30.
//

#include <stdio.h>
#include <memory>
#include "headers.h"

class testSharedPtr
{
public:

    std::shared_ptr<int> m_ptr = std::make_shared<int>(10000);
    std::unique_ptr<int> m_up;
    std::weak_ptr<int> m_wp;
    testSharedPtr()
    {
        m_ptr = std::make_shared<int>(10);
        m_up = std::make_unique<int> (110);
        m_wp = m_ptr;
    }
};

void shared_ptr_main()
{
    testSharedPtr a;
    cout << *a.m_ptr << endl;
    cout << *a.m_up << endl;
    cout << *(a.m_wp.lock()) << endl;

    std::shared_ptr<int> ppp = std::shared_ptr<int>(nullptr);
    if(!ppp)
    {
        cout << " NULL ptr" << endl;
    }
    std::shared_ptr<int> ppp2 = nullptr;
    if(!ppp2)    {
        cout << " NULL ptr" << endl;
    }


}

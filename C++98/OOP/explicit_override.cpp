//
//  explicit_override.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-29.
//

#include <stdio.h>

class Base
{
    public:
        virtual void func() = 0;
};

class Derived final: public Base
{
    public :
        void func() override
        {
            int a = 0;
        } ;
};

//class Derived3 : public Derived    // invalid , since Derived is final
//{
//    public :
//
//};

//
//  destructor.cpp
//  testcpp3
//
//  Created by hua fan on 2024-11-14.
//

#include <iostream>
#include <memory>

using namespace std;

class dog
{
    public:
        virtual ~dog()
        {
            cout << "dog destructed" << endl;
        }
};

class yellowdog : public dog
{
    public:
        virtual ~yellowdog()
        {
            cout << "yellow dog destructed" << endl;
        }
};

class dogfactory
{
public:
    static unique_ptr<dog> createYellowDog()
    {
        return make_unique<yellowdog>();
    }
};

void destructor_main()
{
    unique_ptr<dog> p = dogfactory::createYellowDog();


}

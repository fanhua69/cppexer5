//
//  shared_ptr_3.cpp
//  testcpp3
//
//  Created by hua fan on 2024-11-09.
//

#include <string>
#include <memory>
#include <iostream>

using namespace std;

class Animal
{
    public:
        virtual void bark()
        {
            cout << "Barking Animal" << endl;
        }
};

class Dog : public Animal
{

public:
    string name_;

    Dog(string name)
    {
        cout << "Created:" << name << endl;
        name_=name;
    }

    Dog()
    {
        cout << "Nameless created" << endl;

    }

    Dog(Dog && o)
    {
        cout << "Created by rvalue:" << o.name_ << endl;
        this->name_ = std::move(o.name_);
    }

    ~Dog()
    {
        cout << "Deleted:" << name_ << endl;
    }

    void bark()
    {
        cout << "dog:" << name_ << "rules" << endl;
    }
};

void foo3()
{
    Dog d;
    cout << d.name_ << endl;
}

void shared_ptr3_main()
{
    foo3();
}


//
//  constructor_virtual.cpp
//  testcpp3
//
//  Created by hua fan on 2024-11-14.
//

#include <iostream>
#include <string>
using namespace std;

class Dog3
{
public:
    Dog3() { cout << "Dog born" << endl; }
    virtual void bark() { cout << "I am just a dog " << endl; bark();}
    void seeCat() { bark();};
    virtual ~Dog3() { cout << " base dog destructed " << endl;}
};

class YellowDog3: public Dog3
{
public:
    YellowDog3() { cout << "Yellow dog born" << endl;}
    virtual void bark() override { cout << "I am a yellow dog" << endl;}
    virtual ~YellowDog3() { cout << "Yellow dog destructed" << endl; }
};

void constructor_virtual_main()
{
    YellowDog3 d;
    d.seeCat();
}

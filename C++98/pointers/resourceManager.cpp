//
//  resourceManager.cpp
//  testcpp3
//
//  Created by hua fan on 2024-11-10.
//

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Person
{
public:
    Person(string name): pName_ (new string(name))
    {}

    ~Person()
    {
        cout << "Person deleted:" << pName_ << endl;
        delete pName_;
    }

    void printName()
    {
        cout << pName_ <<endl;
    }

    string* pName_;

};

void ResourceManagerMain()
{
    vector<Person> persons;
    persons.push_back(Person("George"));
    persons.front().printName();
    cout <<  " bye " << endl;
}

//
//  random.cpp
//  testcpp3
//
//  Created by hua fan on 2024-11-12.
//
#include <random>
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <any>

using namespace std;

void setAge(const int &a)
{
    int a11= a;
}

void setAge(int &a)
{
    int aa = a;
}

void random_main_2()
{
    std::default_random_engine eng;
    cout <<"Min:" << eng.min() << endl;
    cout <<"Max:" << eng.max() << endl;
    cout << eng() << endl;
    cout << eng() << endl;

    std::stringstream ss;
    ss << eng;

    const int a = 10;
    setAge(a);

    std::any a1 = 1012321;
    cout << std::any_cast<int>(a1) << endl;




}

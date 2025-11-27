//
//  requires.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-13.
//

#include <stdio.h>
#include "headers.h"


template<class T>
concept Check = requires
{
    T().clear();
};

template <typename T>
static void print(T t) requires std::is_integral_v<T>
{
    cout << t << endl;
}

template <Check T>
struct G{};



void requires_main()
{
    G<std::vector<char>> x;
    G<std::string> y;

    string z("dsafdsafsd");
    cout << z << endl;
    z.clear();
    cout << z << endl;

}

//
//  index_squence_cpp.cpp
//  testcpp3
//
//  Created by hua fan on 2024-03-30.
//

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

template <typename T>
int  PrintArg(const T& t)
{
    cout << t << " , ";
    return 1;
}

template <typename ...Args>
void ShowList(Args... args)
{
     auto v = {(PrintArg(args),0)...};
    for (auto a : v)
    {
        cout << a << endl;
    }
}

void integer_squence_main()
{
    ShowList(1, 'x', 1.1, string("hello world"), "asdf", 2, 4 );
    cout << endl;
    ShowList(1,2,3,4,5,6,7,8);
    cout << endl;
}

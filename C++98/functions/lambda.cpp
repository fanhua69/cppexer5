//
//  lambda.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-14.
//

#include <stdio.h>
#include "headers.h"

double func1(char c) noexcept(false)
{
    throw(std::exception());
    throw(1);
    return 0;
}

void lambda_main()
{
    try
    {
        func1('c');
    }
    catch(std::exception &ex)
    {
        cout << ex.what() << endl;
    }
    catch(...)
    {
        cout << "what " << endl;
    }


    auto res = std::make_unique<int>(1);

    auto add = [v1 = 10, v2= std::move(res)](int  x, int &y)mutable ->int
                {
                    x+=30;
                    return x + y + v1 + (*v2);
                };


    int a = 0;
    auto f2 = [=]() mutable
                {
                   return ++a;
                };
    cout << f2() << endl;
    cout << a << endl;

    cout <<" size of short : " << sizeof(short) << endl;
    cout <<" size of short int : " << sizeof(short int) << endl;
    cout <<" size of int : " << sizeof(int) << endl;
    cout <<" size of long : " << sizeof(long) << endl;
    cout <<" size of long int : " << sizeof(long int) << endl;
    cout <<" size of long long : " << sizeof(long long) << endl;
    cout <<" size of long long int : " << sizeof(long long int) << endl;
}

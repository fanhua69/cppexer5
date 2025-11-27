//
//  variadicTemplate.cpp
//  testcpp2
//
//  Created by hua fan on 2023-09-13.
//

#include <stdio.h>
#include "headers.h"

template <typename ...types>
class mytuple;

template <typename Head, typename ...Tail>
class mytuple<Head, Tail...> : private mytuple<Tail...>
{
public:
    Head head;
    void print()
    {
        cout << head ;

    }

};


template <typename T>
void printff(const char *s, T value)
{
    cout << value ;
}

template <typename T, typename ...Args>
void printff(const char *s, T value, Args... args)
{

    while(*s)
    {
        if(*s == '%') {
            if(*(s+1) == '%') {
                ++s;
            }
            else {
                cout << value ;

                // call even when *s == 0 to detect extra arguments:
                const char *ps = s+1;
                printff( ps,  args...);
                return ;
            }
        }
        else
        {
            s++;
        }
    }

    cout << "extra arguments are provided to printf" << endl;
}


void variadic_tamplate2_main()
{
    printff( "%d %d %d", 1,2, 3, 4, 5);
}

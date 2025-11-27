//
//  move_constructor.cpp
//  testcpp3
//
//  Created by hua fan on 2023-12-30.
//

#include <stdio.h>
#include "headers.h"

class TTT
{
    public:
        TTT()
        {
            cout << "no parameter constructor" << endl;
            c = 10;
        }
        TTT(TTT&& t)
        {
            cout << "Move constructor " << endl;
            c = 20;
        }

        TTT(const TTT &a)
        {
            cout << "construcor" << endl;
            c = 30;
        }
        TTT( TTT & t)
        {
            cout << "22 construcor" << endl;
            c = 40;
        }
        int c= 0;


        TTT & operator = (const TTT & t)
        {
            if(this == &t)
            {
                return *this;
            }

            c = t.c;
            return *this;
        }

        TTT & operator = (TTT && a)
        {
            if(this == &a)
            {
                return *this;
            }

            c = a.c;
            return *this;
        }
};


TTT getTTT()
{
    TTT t;
    t.c = 1234;
    return t;
}


void move_constructor_main()
{
    TTT && a = getTTT();
    TTT b(a);

    cout << " endl " << endl;
}

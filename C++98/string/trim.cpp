//
//  trim.cpp
//  testcpp3
//
//  Created by hua fan on 2024-05-05.
//

#include <stdio.h>
#include "headers.h"

void trim_main()
{
    string s= "    1234  ";
    cout << s.find_last_not_of(' ') <<endl;
    s.erase(s.find_last_not_of(' ') + 1);
    s.erase(0, s.find_first_not_of(' '));

    cout <<":" << s << ":" << endl;



    for (int i = 0; i < 10; i++)
    {
        int n = 10;
        int h = 20;

        for(int i = 10; i <20; i++)
        {
            int m = 0;
        }
    }
}

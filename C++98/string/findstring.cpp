//
//  findstring.cpp
//  testcpp3
//
//  Created by hua fan on 2025-06-30.
//

#include "headers_2.h"
#include <iostream>
using namespace std;

void findstring_main()
{
    string s = "abcdefghijklmnopqrstuvwxyz";
    size_t f = 0;
    do{
        auto p4 = s.find_first_of("cdefgh", f);
        if(p4 == string::npos)
            break;
        
        cout << "p4:" <<  p4 << " --> " << s[p4] << endl;
        f = p4 + 1;
    } while(true);
}

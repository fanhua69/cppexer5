
//
//  regex_5.cpp
//  testcpp3
//
//  Created by hua fan on 2024-11-11.
//


#include <regex>
#include <iostream>

using namespace std;

void regex_5_main()
{
    string str;

    while(true)
    {
        cin >> str;
        regex e("abc*");
        bool match = regex_match(str, e);
        cout << (match ? "Matched":"Not match" ) << endl << endl;
    }
}

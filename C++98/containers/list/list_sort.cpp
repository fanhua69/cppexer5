//
//  list_sort.cpp
//  testcpp3
//
//  Created by hua fan on 2024-02-11.
//

#include <stdio.h>
#include <list>
#include <algorithm>
#include "print.h"
#include <vector>

void list_sort_main()
{
    std::list<int> a {1,2,3,4,5};


    //std::sort(a.begin(), a.end()); //compiling errors
    std::list<int> b{1,2,3,4,5};
    b.sort();
    std::vector <int> s {1,2,3};
    sort(s.begin(), s.end());
//    std::remove(b.begin(), b.end(), 2);


    std::string s2 = "1234567";
    auto n = s2.find_first_of("988" );
    if(n != string::npos)
        cout << "n:" << n << endl;
    else
        cout << "npos:" << n << endl;

    int n2 = s2.find_last_of("345");
    cout << "n2:" << n2 << endl;

    int n3 = s2.find_first_not_of("12345");
    cout << "n3:" << n3 << endl;

    int n4 = s2.find_last_not_of("12345");
    cout << "n4:" << n4 << endl;

    string ss = s2.substr(2,3);
    cout << ss << endl;


    tuple <int,int,int> v {1,2,3};
    auto [v1, v2 ,v3] = v;
    print(v1,v2,v3);


    print(s2);
}

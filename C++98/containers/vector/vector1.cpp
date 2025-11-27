//
//  vector1.cpp
//  testcpp3
//
//  Created by hua fan on 2024-02-01.
//

#include <stdio.h>
#include "headers.h"

void vector_1_main()
{
    vector<int> v;
    cout << "size:" << v.size() << endl;
    cout << "capacity:" << v.capacity() << endl;

    v.push_back(1);
    cout << "size:" << v.size() << endl;
    cout << "capacity:" << v.capacity() << endl;


    v.push_back(2);
    v.push_back(3);

    cout << "size:" << v.size() << endl;
    cout << "capacity:" << v.capacity() << endl;

    v.push_back(4);
    v.push_back(5);

    cout << "size:" << v.size() << endl;
    cout << "capacity:" << v.capacity() << endl;

    for(int i = 6; i < 67; i++)
    {
        v.push_back(i);
    }
    cout << "size:" << v.size() << endl;
    cout << "capacity:" << v.capacity() << endl;


    v.resize(129);
    cout << "after resize 129 , size:" << v.size() << endl;
    cout << "capacity:" << v.capacity() << endl;


    v.clear();
    cout << "size:" << v.size() << endl;
    cout << "capacity:" << v.capacity() << endl;

    v.shrink_to_fit();
    cout << "size:" << v.size() << endl;
    cout << "capacity:" << v.capacity() << endl;




}

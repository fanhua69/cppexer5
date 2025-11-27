//
//  templates.cpp
//  testcpp2
//
//  Created by hua fan on 2023-09-03.
//

#include <stdio.h>
#include "headers.h"

template <int N>
int multipleN(int x)
{
    return x*N;
}

class ts
{
public:
    int m;
    int n;
    double d;
};


void templateMain()
{


    ts *pp = (ts*)malloc(sizeof(ts)  * 1000);
    for(int  i =0; i<1000; i++)
        cout << pp[i].d <<",";

    try
    {
        pp = new ts[10];
    }
    catch(exception &e)
    {
        cout << e.what() << endl;
    }

    cout << pp << endl;


}

#include "headers_2.h"
#include <iostream>
using namespace std;

void templates_main()
{
}

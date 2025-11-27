//
//  stringcat.cpp
//  testcpp2
//
//  Created by hua fan on 2023-09-03.
//

#include <stdio.h>
#include "headers.h"


class A
{
public:
    int a;
protected:
    int b;
private:
    int c;
};

class B: A
{
    B()
    {
    a = 10;
    b= 102;
    //c = 300;

    }

};

void stringcon()
{
    const char * ps1 = "abc";
    const char * ps2 = "def";
    const char * ps3 = "abc";


    int tl = strlen(ps1) + strlen(ps2) + 1;

    char * pn = (char*)malloc(tl);
    memset(pn, 0, tl);

    strcpy(pn, ps1);
    strcpy(&pn[strlen(ps1)], ps2);
    cout << pn << endl;

}

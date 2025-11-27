//
//  FibMemoization.cpp
//  testcpp2
//
//  Created by hua fan on 2023-10-01.
//

#include <stdio.h>
#include "headers.h"


static vector<int> mem;

int Fib(int n)
{
    if(mem.size() == 0)
    {
        mem.resize(n+1, -1);
        mem[0] = mem[1] = 1;
    }


    if(mem[n] != -1)
        return mem[n];

    mem[n]= Fib(n-1) + Fib(n-2);

    return mem[n];

}

void FibMain()
{
    cout << Fib(9) << endl;
}

//
//  shared_ptr_2.cpp
//  testcpp3
//
//  Created by hua fan on 2024-02-02.
//

#include <stdio.h>
#include <memory>
#include "headers.h"

static struct B;

static struct A
{
    int m = 1;
    int n = 2;
    std::shared_ptr<B> pb = nullptr;

    A()
    {
        cout << "Constructing A" << endl;
    }

    ~A()
    {
        cout << "destructing A" << endl;
    }
};

static struct B
{
    int o = 4;
    int p = 5;
    std::shared_ptr<A> pa = nullptr;

    B()
    {
        cout << "Constructing B" << endl;
    }

    ~B()
    {
        cout << "destructing B" << endl;
    }
};

void shared_ptr_problem_main()
{
    auto pa = std::make_shared<A>();

    {
        auto pb = std::make_shared<B>();
        pa->pb = pb;
        pb->pa = pa;
    }

    cout << pa.use_count() << endl;

}

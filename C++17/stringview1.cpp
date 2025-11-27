//
//  stringview1.cpp
//  testcpp3
//
//  Created by hua fan on 2025-10-25.
//


#include "headers_2.h"
#include <iostream>
#include <mutex>
#include <future>
#include <functional>


using namespace std;


namespace {
struct myv
{
    explicit myv(int a, int b):x(a), y(b)
    {}
    
    explicit myv(int a) : x(a), y(a) {}
    
    
    myv (const myv &a)
    {
        x = a.x;
        y = a.y;
    }
    
    void operator = (const myv &a)
    {
        x = a.x;
        y = a.y;
    }
    //  myv operator + ( const myv &o)
    //  {
    //      return myv(x+ o.x, y + o.y);
    //  };
    
    myv operator + (int n)
    {
        return myv(x+n, y+n);
    }
    
    explicit operator int() const
    {
        return x+y;
    }
    
    explicit operator double () const
    {
        return x + y * 10;
    }
    void show()
    {
        cout << "x:" << x << ", y:" << y << endl;
    }
    
    void inc() const
    {
        x++;
        y++;
    }
    
    //    int get() const
    //    {
    //        std::lock_guard<mutex> lk(mt);
    //        return x;
    //    }
    
    friend myv operator + (const myv&a, const myv& b);
    
protected:
    mutable int x = 0;
    mutable int y = 0;
    mutable std::mutex mt;
};

int add(int a, int b)
{
    return a + b;
}

myv operator + (const myv&a, const myv &b)
{
    return myv(a.x + b.x, a.y + b.y);
}

}

void stringview2_main()
{
    myv a(1,2), b(3,5);
    myv c = a + b;
    c.show();
    
    c = c + 2;
    c.show();
    
    int n = int(c);
    cout << n << endl;
    
    double d = double(c);
    cout << d << endl;
    
    const myv cc(1,1);
    cc.inc();
    
    std::packaged_task<int(int,int)> t(add);
    std::function<int(int,int)> f(add);
    
    cout << f(1,2) << endl;
    std::future<int> fu = t.get_future();
    t(1,2);
    cout << fu.get() << endl;
    
    
}

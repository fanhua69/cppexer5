//
//  dataflow.cpp
//  testcpp2
//
//  Created by hua fan on 2023-08-25.
//

#include <stdio.h>
#include "headers.h"
#include <chrono>
#include <memory>
#include <thread>

using namespace std::chrono;


class node
{
public:
    shared_ptr<node> _pre;
    shared_ptr<node> _next;

    int _data;
    time_point <steady_clock> _addTime;
    seconds _duration;

    node(int d, seconds duration)
    {
        _addTime = steady_clock::now();
        _duration = duration;
        _data = d;
        _pre = nullptr;
        _next = nullptr;
        cout << "created : " << _data << endl;
    }

    ~node()
    {
        cout << "destructed: " << _data << endl;
    }
};


class datalist
{
public:
    shared_ptr<node> _tail ;
    shared_ptr<node> _head;

    datalist()
    {
        _head = make_shared<node>(-1, seconds(INT_MAX));
        _head = make_shared<node>(0, seconds(INT_MAX));

        _tail = _head;
    }

    void addnode(int data, int lastSeconds)
    {
        shared_ptr<node> p = make_shared<node>(data, seconds(lastSeconds));
        _tail->_next = p;
        p->_pre  = _tail;
        _tail = p;
    }
};

void deleteNodes(datalist &dl, shared_ptr<node> &to)
{
    shared_ptr<node> h = dl._head;
    shared_ptr<node> pre = h;
    h = h->_next;

    while(h)
    {
        if ( h == to)
        {
            cout << "deleted node: " << h->_data << endl;
            pre->_next = h->_next;
            if(h->_next)
            {
                h->_next->_pre = pre;
            }
            break;
        }
        pre = h;
        h = h->_next;
    }
}

void checkTime(datalist &dl)
{
    shared_ptr h = dl._head;
    while(h)
    {
        steady_clock::time_point nt = steady_clock::now();
        seconds d = duration_cast<seconds> (nt - h->_addTime);
        if( d >= h->_duration)
        {
            deleteNodes(dl, h);
            h = dl._head;
        }
        else
        {
            h = h->_next;
        }
    }
}

void printList(datalist &dl)
{
    shared_ptr<node> p = dl._head;
    while(p)
    {
        cout << "(" << p->_data << ", "<< p->_duration.count() << ")";
        p=p->_next;
    }
    cout << endl;
}

void dataflowMain()
{
    datalist dl;
    dl.addnode(1,1);
    dl.addnode(2,2);
    dl.addnode(3,3);
    dl.addnode(5,4);
    dl.addnode(6,5);
    dl.addnode(7,7);
    dl.addnode(8,9);
    dl.addnode(9,10);
    dl.addnode(10,11);

    while(true)
    {
        cout << "sleeping..." << endl;
        this_thread::sleep_for(seconds(1));
        checkTime(dl);
        printList(dl);
    }
}

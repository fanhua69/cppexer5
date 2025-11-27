//
//  timedQueue.cpp
//  testcpp2
//
//  Created by hua fan on 2023-08-25.
//

#include <stdio.h>
#include <chrono>
#include <memory>
#include <thread>
#include <iostream>
#include <mutex>



using namespace std::chrono;
using namespace std;

std::mutex g_dlMutex;
std::mutex g_coutMutex;

namespace timed_queue
{

class node
{
public:
    int _data;
    time_point<steady_clock> _addTime;
    seconds _duration;

    shared_ptr<node> _pre;
    shared_ptr<node> _next;

    node(int d, int s)
    {
        _data = d;
        _duration = seconds(s);
        _addTime = steady_clock::now();
        _pre = nullptr;
        _next = nullptr;
    }
};

class dataList
{
public:
    shared_ptr<node> _head;
    shared_ptr<node> _tail;

    dataList()
    {
        _head = make_shared<node> (-1, INT_MAX);
        _tail = _head;
    }

    void addNode(int d, int s)
    {
        shared_ptr<node> p = make_shared<node> (d, s);

        std::lock_guard<mutex> g(g_dlMutex);
        _tail->_next = p;
        p->_pre = _tail;
        _tail = p;
    }
};

dataList g_dl;


void printList()
{
    lock_guard<mutex> g(g_coutMutex);
    shared_ptr<node> h = g_dl._head;
    while(h)
    {
        cout << h->_data << ", " ;
        h=h->_next;
    }
    cout << endl;
}

void addNodeThread()
{
    while(true)
    {
        int d, s;
        {
            lock_guard<mutex> cg(g_coutMutex);
            cout << "Node data: " ;
            cin >> d;
            cout << "Node duration: " ;
            cin >> s;
        }

        g_dl.addNode(d,s);
        printList();

        this_thread::sleep_for(milliseconds(1000));
    }
}


void deleteNode(shared_ptr<node> &dn)
{
    shared_ptr<node> h = g_dl._head;
    shared_ptr<node> pre = h;
    h = h->_next;

    {
        lock_guard<mutex> gc(g_coutMutex);
        cout << "deleting : " << dn->_data << endl;
    }

    while(h)
    {
        if (h == dn)
        {
            lock_guard<mutex> g(g_dlMutex);
            pre ->_next = h->_next;
            if(h->_next)
            {
                h->_next ->_pre = pre;
            }
            break;
        }

        pre = h;
        h = h->_next;
    }

    printList();
}

void checkList(dataList &dl)
{


    shared_ptr<node> h = dl._head;
    while(h)
    {
        time_point<steady_clock> t = steady_clock::now();
        seconds s = duration_cast<seconds> ( t - h->_addTime);
        {
            //lock_guard<mutex> gc(g_coutMutex);
            //cout << "checking : " << h->_data << endl;
        }
        if(s.count() > h->_duration.count())
        {
            deleteNode(h);
            h = dl._head;
        }
        else
        {
            h = h->_next;
        }
    }
}

void deleteThread()
{


    while(true)
    {
        this_thread::sleep_for(milliseconds(5200));
        {
            checkList(g_dl);
        }
    }
}

void timedQueueMain()
{
    thread t1(&addNodeThread);
    thread t2(&deleteThread);

    t1.join();
    t2.join();

}

}

#include "headers_2.h"
#include <iostream>
using namespace std;

void timedQueue_main()
{
}

//
//  mapList.cpp
//  testcpp2
//
//  Created by hua fan on 2023-08-27.
//

#include <stdio.h>
#include <memory>
#include <chrono>
#include <map>
#include <thread>
#include <iostream>
#include <queue>


namespace mapList
{
using namespace std;
using namespace std::chrono;

class Node
{
public:
    int _data;
    time_point<steady_clock> _begin;
    seconds _duration;
    shared_ptr<Node> _pre;
    shared_ptr<Node> _next;

    Node(int d, int s)
    {
        _data = d;
        _duration = seconds(s);
        _begin = steady_clock::now();
    }
};

time_point<steady_clock> g_begin;
multimap<seconds, shared_ptr<Node>> g_map;

auto comp = [](shared_ptr<Node> &lhs, shared_ptr<Node> &rhs)
{
    return lhs->_duration > rhs->_duration;
};

priority_queue<shared_ptr<Node>, vector<shared_ptr<Node>>, decltype(comp)> g_queue;

class timeList
{
public:
    shared_ptr<Node> _guard;
    shared_ptr<Node> _tail;

    timeList()
    {
        _guard = make_shared<Node>(-1, INT_MAX);
        _tail = _guard;
    }

    void addNode(int data, int sec)
    {
        seconds totald = duration_cast<seconds>(steady_clock::now() - g_begin) + seconds(sec);
        shared_ptr<Node> newNode = make_shared<Node>(data, totald.count());
        newNode->_pre = _tail;
        _tail->_next = newNode;
        _tail = newNode;

        g_map.insert({totald, newNode});
        g_queue.push(newNode);
    }

    void deleteNode(shared_ptr<Node> n)
    {
        shared_ptr<Node> p = _guard;

        while(p && p!=n)
        {
            p=p->_next;
        }

        if(p == n)
        {
            p->_pre->_next = p->_next;
            p->_next->_pre = p->_pre;
        }
    }


    void printNodes()
    {
        auto h = _guard;
        while(h)
        {
            cout <<"[" <<  h->_data << ", " << h->_duration .count() << "]" ;
            h = h->_next;
        }
        cout << endl;
    }

    void deleteNode2(shared_ptr<Node> n)
    {
        if( n ==_tail)
        {
            _tail = n->_pre;
            _tail->_next = nullptr;
        }
        else
        {
            n->_pre->_next = n->_next;
            if(n->_next)
                n->_next->_pre = n->_pre;
        }


    }
};

timeList g_tl;

void printMapNodes()
{
    for(auto it = g_map.begin(); it != g_map.end(); ++it)
    {
        cout << "[" << it->first.count() << "," << it->second->_data << "] ";
    }
    cout << endl;
}

void checkNodes()
{
    seconds d = duration_cast<seconds>(steady_clock::now() - g_begin);
    for(auto it = g_map.begin(); it!= g_map.end();)
    {
        if(it->first.count() <= d.count())
        {
            g_tl.deleteNode2(it->second);
            it = g_map.erase(it);
        }
        else
        {
            it++;
        }
    }
}

void checkNodesWithPriorityQueue()
{
    seconds d = duration_cast<seconds>(steady_clock::now() - g_begin);
    cout << "Passed: " << d.count() << endl;
    while(g_queue.size() && g_queue.top()->_duration.count() <= d.count())
    {
        g_tl.deleteNode2(g_queue.top());
        g_tl.printNodes();
        g_queue.pop();
    }
}


void mapListMain()
{

    g_begin = steady_clock::now();
    g_tl.addNode(1,10);
    g_tl.printNodes();
    this_thread::sleep_for(seconds(1));
    g_tl.addNode(2,10);
    g_tl.printNodes();
    this_thread::sleep_for(seconds(1));
    g_tl.addNode(3,10);
    g_tl.printNodes();
    this_thread::sleep_for(seconds(1));
    g_tl.addNode(4,10);
    g_tl.printNodes();

    while(g_map.size() )
    {
        this_thread::sleep_for(seconds(1));
        checkNodesWithPriorityQueue();
    }
}


}



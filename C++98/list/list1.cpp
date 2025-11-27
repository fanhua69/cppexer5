//
//  list1.cpp
//  testcpp3
//
//  Created by hua fan on 2025-09-21.
//


#include "headers_2.h"
#include <iostream>
using namespace std;

namespace
{
struct node
{
    int val;
    node *next;
    node (int i ) {
        val = i;
        next = nullptr;
    }
    ~node()
    {
        cout << "Destructing : " << val << endl;
    }
};


void des_list(node *head)
{
    if(!head)
        return;
    des_list(head->next);
    delete head;
}

void des_list2(node *head)
{
    while(head)
    {
        node *temp = head;
        head = head->next;
        delete temp;
    }
}

}

void list1_main()
{
    node *head = nullptr;
    for(int i = 0; i < 5; ++i)
    {
        node *p = new node(i);
        if(!head)
        {
            head = p;
        }
        else
        {
            node *tail = head;
            while(tail->next)
            {
                tail = tail->next;
            }
            tail->next = p;
        }
    }
    
    des_list2(head);
    
    
    
    
}

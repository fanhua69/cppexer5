//
//  compare_exchange_weak.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-01.
//

#include <stdio.h>
#include "headers.h"
#include <mutex>

template <typename T>
class lock_free_stack
{
private:
    struct node
    {
        T data;
        node *next;

        node(T const &data_) : data(data_)
        {
        }
    };

    std::atomic<node*> head;

public:
    void push(T const &data)
    {
        node *const new_node = new node(data);
        new_node->next = head.load();
        while(!head.compare_exchange_weak(new_node->next, new_node))
        {};
    }
};



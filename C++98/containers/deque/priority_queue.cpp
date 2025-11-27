//
//  priority_queue.cpp
//  testcpp2
//
//  Created by hua fan on 2023-12-17.
//

#include <stdio.h>
#include <queue>
#include <vector>
#include <iostream>
#include <string_view>
#include <map>
#include "headers_2.h"

using namespace std;


template<typename Adaptor>
requires (std::ranges::input_range<typename Adaptor::container_type>)
void print(std::string_view name, const Adaptor& adaptor)
{
    struct Printer : Adaptor
    {
        void print(std::string_view name) const
        {
            std::cout << name << " [ " << std::size(this->c) << "]: ";
            for(auto const &elem : this -> c)
                std::cout << elem << ' ';
            cout << '\n';
        }
    };

    static_cast<Printer const&> (adaptor).print(name);
}

void priority_queue_main()
{
    auto l = [](int a, int b )
    {
        return a < b;
    };

    priority_queue<int, vector<int>, decltype(l)> q(l);
    q.push(1);
    q.push(2);
    q.push(10);
    q.push(8);
    
//    print(q);

    while(q.size())
    {
        cout << q.top() << endl;
        q.pop();
    }

    std::vector<std::string> v1 {"1","2","1","4"},
                            v2 {"CA", "B", "FC","DD","E"};

    std::priority_queue s1(std::less<>(), std::move(v1));
    std::priority_queue s2(std::greater<>(), std::move(v2));

    print("s1:", s1);
    print("s2:", s2);


    std::priority_queue<int> q2;
    q2.push(1);
    q2.push(3);
    q2.push(5);
    print("q2:",q2);
    while(q2.size())
        {
        cout << q2.top() << endl;
        q2.pop();
        }



}

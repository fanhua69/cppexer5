//
//  structured_binding.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-29.
//

#include <stdio.h>
#include <map>
#include <string>
#include "headers.h"

template <typename Key, typename Value, typename F>
void update(std::map<Key,Value> &m, F foo)
{
    for(auto [k, v] : m) m[k] = foo(k);
}

struct Point
{
    int x;
    int y;

};

namespace std
{
    template <>
    struct hash<Point>
    {
        std::size_t operator()(const Point &p) const
        {
            size_t t1 = std::hash<int>{}(p.x);
            size_t t2 = std::hash<int>{}(p.y);
            return t1 ^ (t2 << 1);
        }
    };
}

void structured_binding_main()
{
    std::map<std::string, unsigned long> m {{"a", 1}, {"b",2}, {"c", 3}};

    for(const auto [k, v] : m )
        cout << k << ", " << v << endl;

    std::hash<std::string> f;
    auto n = f("a");
    cout <<n <<endl;

    update(m, [](std::string key){
                    return std::hash<std::string>{} (key);
                });

    for(auto [k, v] : m)
    {
        cout << k << ", " << v << endl;
    }

    Point p{1,2};
    size_t h = std::hash<Point>{}(p);
    cout << h << endl;
}

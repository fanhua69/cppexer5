//
//  ranges3.cpp
//  testcpp3
//
//  Created by hua fan on 2025-09-09.
//


#include <concepts>
#include "headers_2.h"
#include <span>


using namespace std;

template <typename T>
concept intdata = requires (T t)
{
    {t}->std::same_as<int&>;
};

template <typename T>
requires intdata<T>
T add(T a, T b)
{
    return a + b;
}

void printa(span<const int> s)
{
    for (auto v: s)
        cout << v << " ";
    cout << endl;
    cout << s.size() << endl;
    cout << s.size_bytes() << endl;
}

void ranges3_main()
{
    add(1,3);
    int arr[]={1,2,3};
    printa(arr);
    
    vector<int> v = {1,2,3};
    printa(v);
    
    array<int, 3> a = {1,2,3};
    printa(a);

}

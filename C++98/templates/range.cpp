//
//  range.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-17.
//

#include <stdio.h>
#include "headers.h"
#include <ranges>

struct Type
{
    int *begin();
    int *end();
};

void range_main()
{
    static_assert(std::ranges::range<Type>);

    std::vector<int> numbers = {1,2,3,4,5};
    auto view2 = numbers | std::views::transform([](int x) { return x % 2 == 0 ? x * 2: x*3;});
    cout << typeid(view2).name() << endl;

    std::ranges::drop_view f(numbers,2);
    for(int i : f)
        cout <<i << endl;

    auto v11 = std::views::iota(1,11);
    cout <<typeid(v11).name() << endl;

    auto v12 = std::views::take(numbers, 3);
    cout <<typeid(v12).name() << endl;

    std::views::take;// ft(numbers,3);

    for(auto i : v12)
        cout << i << endl;

    string a = "12342314234";

    auto va = std::string_view(a);
    cout <<typeid(va).name() << endl;

    for(auto i : va)
        cout << i << endl;


    std::map<int,int> m {{1,11}, {2,12}, {3,13}};
    auto vvv = std::views::values(m) | std::views::take(2);
    for(auto i : vvv)
        cout << i << " , key " << endl;





}

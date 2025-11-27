//
//  range4.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-20.
//

#include <stdio.h>
#include "headers.h"
#include <ranges>
#include <algorithm>


struct Space
{
    bool operator == (auto pos) const
    {
        return *pos == ' ';
    }
};

struct NegativeNumber {
    bool operator == (auto num) const
    {
        return *num < 0;
    }
};

struct Sum
{
    void operator () (auto n)
    {
        sum += n;
    }

    int sum{0};
};

struct five
{
    bool operator == ( int *i) const
    {
        return *i ==5;
    }

};

void range4_main()
{
    const char * codingriji = "subscribed to my wechat official account codingriji";

    std::ranges::for_each(codingriji, Space(), [](char c) { cout << c ;});
    cout << endl;

    vector<int> s {1,2,2,3,5};
    std::for_each(s.begin(), s.end(),  [](auto i){cout << i << endl;});
    std::ranges::for_each(s.begin(), s.end(), [](auto i) { cout << i << endl;});

    auto sr = std::ranges::subrange{codingriji, Space{}};
    for( auto c : sr)
    {
        cout << c;
    }

    for(auto c : std::ranges::subrange{codingriji, Space{}})
        cout << c << ", " ;

    std::vector<int> myVec {5,10,33,-5,10,10086,10010};

    auto [temp1, sum] = std::ranges::for_each(myVec, Sum{});
    cout << *temp1 << endl;
    cout << "Sum: " << sum.sum << '\n';


    auto [tmp2, sum2] = std::ranges::for_each(std::begin(myVec), NegativeNumber{},Sum{});
    std::cout << "Sum: " << sum2.sum << '\n';
}

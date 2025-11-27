//
//  std_views_split.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-17.
//

#include <iomanip>
#include <stdio.h>
#include "headers.h"
#include <ranges>
#include <string_view>
#include <iomanip>
#include <iostream>
#include <ranges>
#include <string>
#include <string_view>

class SomeData
{
public:
  // ...
    const std::vector<int>& Get() const { return data_; }
    private:
        std::vector<int> data_;
};

SomeData Foo()
{
    return SomeData();
}

void std_views_split_main()
{
    using namespace std::literals;

    // returns the original string (not splitted)
    auto splittedWords1 = std::views::split("one:.:two:.:three", ":.:");

    string s = "sasdfsdf";
    cout << std::quoted(s) << endl;
    cout << s << endl;
    cout << std::string_view(s) << endl;

    for (const auto word : splittedWords1)
       // cout << *word << endl;
        std::cout << std::quoted(std::string_view(word));

    std::cout << std::endl;

    auto f = Foo();
    for (int v: f.Get())
    {
        std::cout << v << ',';
    }

}

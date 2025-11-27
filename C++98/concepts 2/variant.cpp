//
//  variant.cpp
//  testcpp3
//
//  Created by hua fan on 2024-12-13.
//

#include <variant>
#include <iostream>
#include <iomanip>
#include <iostream>
#include <string>
#include <type_traits>
#include <variant>
#include <vector>

using namespace std;

template <typename ...Ts>
struct overload : Ts ...
{
    using Ts::operator ()...;
};


void applyParam(const auto& var, auto param)
{
    std::visit(overload{
        [&param](const auto& item) {  
            checkParam(item, param);
        },
    }, var);
}

void variant_main()
{
    std::variant<string, int> v1 = 123;

    auto visitor = [](auto &d)
    {
        if(is_same_v<decay_t<decltype(d)>, string>)
        {
            cout << "data in variant:" << d << endl;
        }
        else if(is_same_v<decay_t<decltype(d)>, int>)
        {
            cout << "integer" << endl;
        }
        else
        {
            cout << " nothing " << endl;
        }
    };

    std::visit(visitor, v1);

    std::variant<int, double, std::string> my_variant = 3.14;

    auto visitor2 = [](const auto& value) {
        if constexpr (std::is_same_v<decay_t<decltype(value)>, int>) {
            std::cout << "Integer: " << value << std::endl;
        } else if constexpr (std::is_same_v<decay_t<decltype(value)>, double>) {
            std::cout << "Double: " << value << std::endl;
        } else if constexpr (std::is_same_v<decay_t<decltype(value)>, std::string>) {
            std::cout << "String: " << value << std::endl;
        }
    };

    std::visit(visitor2, my_variant);





}

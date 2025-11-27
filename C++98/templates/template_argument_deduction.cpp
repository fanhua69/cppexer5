//
//  template_argument_deduction.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-11.
//

#include <stdio.h>
#include <utility>
#include "headers.h"
#include <array>


void template_argument_deduction_for_class_templates_main()
{

    auto p = std::make_pair(1,3);
    std::pair p2 {2,3};
    pair p3 (3,4);
    auto p4 = new pair{5,6};
    cout << p.first << ", " << p.second<< endl;
    cout << p2.first << ", " << p2.second<< endl;
    cout << p3.first << ", " << p3.second<< endl;
    cout << p4->first << ", " << p4->second<< endl;


    std::array <int, 3> arr{1,2,3};
    constexpr int n = 10;
    std::array <double, n>  arr4;

    array a5 = { 1,2,3,4,5};
    for (auto i : a5)
        cout << i << endl;


    constexpr auto str = std::to_array("abd");
    for(auto i : str)
        cout << i << endl;


    constexpr auto str2 = std::to_array<double>({1,2,3});
    for(auto i : str2)
        cout << i << endl;


}

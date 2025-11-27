//
//  tuple1.cpp
//  testcpp3
//
//  Created by hua fan on 2024-02-01.
//

#include <stdio.h>
#include <tuple>

#include "headers.h"

auto get_student(int id)
{
    if(id ==0)
        return std::make_tuple(3.5, 'A', "zhang");

    if(id == 1)
        return std::make_tuple(3.6, 'B', "Li");

    if(id == 2)
        return std::make_tuple(1.2 , 'C', "ZZZ");

    return std::make_tuple(0.0, 'D', "NULL");
}

void tuple_main()
{
    auto student = get_student(0);
    cout << "ID: 0, "
        << std::get<0>(student) <<", "
        << std::get<1>(student) << ", "
        << std::get<2>(student) << endl;

    student = get_student(1);
    cout << "ID: 0, "
        << std::get<0>(student) <<", "
        << std::get<1>(student) << ", "
        << std::get<2>(student) << endl;

    double g;
    char gr;
    string n;
    std::tie(g, gr, n) = get_student(1);
    cout << g  << ", " << gr << " , " << n << endl;

    std::tie(g, gr, n) = get_student(2);
    cout << g  << ", " << gr << " , " << n << endl;

    auto [a,b,c] = get_student(1);
    cout << "structured binding: " <<  a << ", " << b << ", " << c << endl;

    std::tuple<double, char, string> s = get_student(1);
    cout << std::get<double> (s) << endl;

    std::tuple<double , int > s2 {1.2,2.3};
    cout << std::get<double>(s2) << endl;

    cout << " --------------------------- " << endl;

    auto t3 = std::tuple_cat(std::move(s), std::move(s2));
    cout << std::get<0>(t3) << endl;
    cout << std::get<1>(t3) << endl;
    cout << std::get<2>(t3) << endl;
    cout << std::get<3>(t3) << endl;
    cout << std::get<4>(t3) << endl;
//    cout << std::get<5>(t3) << endl;


    //

}

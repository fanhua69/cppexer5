//
//  capture_value_initialization.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-29.
//

#include <stdio.h>
#include "headers.h"
#include <typeindex>

#include <memory>



void capture_value_initialization_main()
{
    auto im = std::make_unique<int>(10);

    auto calc = [n = 10, im = std::move(im)] ( auto p){ return p * n * *im;};

    cout << calc(112) << endl;


    std::type_index a = typeid(int);
    cout << a.name() << endl;
    cout << a.hash_code() << endl;



}

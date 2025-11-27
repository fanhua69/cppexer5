//
//  unique_pointer.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-05.
//

#include <stdio.h>
#include <memory>

auto f(std::unique_ptr<int> ptr)
{
    *ptr = 32;
    return ptr;  // This is valid since "copy elision"
}


void unique_ptr_main()
{
    auto ptr = std::make_unique<int>();
    ptr = f(std::move(ptr));  // unique_ptr is not copiable
}

//
//  explicit_delete_default_constructor.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-29.
//

#include <stdio.h>

class Magic
{
    public:
        Magic() = default;
        Magic(int m) {};
        Magic& operator = (const Magic &) = delete;
};

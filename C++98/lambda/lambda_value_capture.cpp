//
//  lambda_value_capture.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-29.
//

#include <stdio.h>
#include "headers.h"

void lambda_value_capture_main()
{
    int value = 1;
    auto copy_value = [value]
    {
        return value;
    };

    value = 100;

    auto stored_value = copy_value();
    cout << "Stored Value: " << stored_value << endl;

    auto ref_value = [&value]
    {
        return value;
    };

    value = 200;

    auto stored_value_2 = ref_value();
    cout << "Ref Value: " << stored_value_2 << endl;

}

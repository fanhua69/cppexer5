//
//  mdspan.cpp
//  testcpp3
//
//  Created by hua fan on 2025-11-12.
//


#include "headers_2.h"
#include <iostream>
#include <mdspan>

using namespace std;

void mdspan_main()
{
    double data[15] = {1,2,3,4,5,6,7,8,9,10};
    std::mdspan<double, std::dextents<size_t, 3>> md(data, 1,3,5);
    cout << md.extent(0) << endl;
    cout << md.rank() << endl;
    
}

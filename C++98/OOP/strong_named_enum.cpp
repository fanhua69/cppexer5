//
//  strong_named_enum.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-29.
//

#include <stdio.h>
#include "headers.h"

enum class new_num: unsigned int
{
    value1,
    value2,
    value3,
    value4=100
};

template <typename T>
std::ostream & operator << (typename std::enable_if<std::is_enum<T>::value, std::ostream>::type& stream,
                            const T& e)
{
    return stream << static_cast<typename std::underlying_type<T>::type>(e) << endl;
}

void strongly_typed_enum_main()
{
    new_num a, b;
    a = new_num::value1;
    b = (new_num)2;

    if(a == new_num::value3)
    {
        cout << "value 3 " << endl;
    }

    if(a == static_cast<new_num>(0))
    {
        cout << "9" << endl;
    }

    cout <<  b  << endl;

    

}

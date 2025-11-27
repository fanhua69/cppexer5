//
//  structured_binding.cpp
//  testcpp3
//
//  Created by hua fan on 2025-01-03.
//

#include <iostream>
#include <map>

using namespace std;

void structured_binding_2_main()
{
    std::map<string, int> mapUsersAge {{"Alex", 45}, {"John", 25}};
    std::map mapCopy{mapUsersAge};

    if(auto [iter, wasAdded] = mapCopy.insert_or_assign("John", 26); !wasAdded)
    {
        cout << iter->first << " reassigned ...\n";
    }

    for(const auto &[key, value] : mapCopy)
    {
        cout << key << ", " << value << '\n';
    }
}

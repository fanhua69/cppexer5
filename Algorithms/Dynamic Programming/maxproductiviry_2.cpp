//
//  maxproductiviry_2.cpp
//  testcpp3
//
//  Created by hua fan on 2025-01-14.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



struct Item
{
    int avail;
    int relia;
};

int max_productivity_3(const vector<int> &a, const vector<int>&r)
{
    vector<Item> machine;
    for(int i = 0; i < a.size(); i ++)
    {
        machine.emplace_back(a[i], r[i]);
    }

    std::sort(machine.begin(), machine.end(),
                [](const Item &a, const Item &b)
                {
                    return a.avail < b.avail;
                }
            );



    int maxp = INT_MIN;
    int sum = 0;
    for(auto it = machine.rbegin(); it != machine.rend(); ++it)
    {
        sum+=it->relia;
        int mp = it->avail * sum;
        if(mp > maxp)
            maxp = mp;
    }


    return maxp;

}

int max_productivity_2_main()
{
    std::vector<int> availability = {4, 3, 2, 1};
    std::vector<int> reliability = {2, 2, 2, 2};
    std::cout << "Max Productivity 3: " << max_productivity_3(availability, reliability) << std::endl;
    return 0;
}

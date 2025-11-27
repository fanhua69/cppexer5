//
//  fintItinerary.cpp
//  testcpp2
//
//  Created by hua fan on 2023-09-23.
//

#include <stdio.h>
#include "headers.h"
#include <algorithm>

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) 
    {
        route_.clear();
        trips_.clear();

        for(const auto &pair : tickets)
            trips_[pair[0]].push_back(pair[1]);

        for(auto &pair : trips_)
        {
            auto &dests = pair.second;
            std::sort(dests.begin(), dests.end());
        }

        const string start = "A";
        visit(start);

        return vector<string>(route_.crbegin(), route_.crend());
    }

private:
    unordered_map<string, deque<string>> trips_;

    vector<string> route_;

    void visit(const string &src)
    {
        auto &dests = trips_[src];
        print(dests);

        while(!dests.empty())
        {
            const string dest = dests.front();
            dests.pop_front();
            visit(dest);
        }
        route_.push_back(src);
    }
};

void findItineraryMain()
{
    Solution a;
    vector <vector<string>> tickets = {{"A","B"}, {"A", "C"}, {"C","A"}};
    vector<string> r = a.findItinerary(tickets);
    print(r);

}

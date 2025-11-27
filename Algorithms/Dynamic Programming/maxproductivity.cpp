//
//  maxproductivity.cpp
//  testcpp3
//
//  Created by hua fan on 2025-01-12.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Server
{
    int availability;
    int reliability;
};

// Comparator to sort servers based on availability in ascending order
bool compare(Server &a, Server &b)
{
    return a.availability < b.availability;
}

int serverStability(vector<Server>& servers)
{
    // Sort the servers by availability
    sort(servers.begin(), servers.end(), compare);
    
    int n = servers.size();
    vector<int> dp(n, 0); // dp[i] stores the maximum stability using servers up to index i
    dp[0] = servers[0].availability * servers[0].reliability;

    // Calculate the maximum stability for each subset of servers
    for (int i = 1; i < n; ++i)
    {
        int minAvailability = servers[i].availability;
        int sumReliability = 0;

        for (int j = i; j < n; ++j)
        {
            minAvailability = min(minAvailability, servers[j].availability);
            sumReliability += servers[j].reliability;
            dp[j] = max(dp[j], minAvailability * sumReliability);
        }
    }

    // The final result is the maximum value in dp
    return *max_element(dp.begin(), dp.end());
}

int max_productivity_main()
{
    // Example Input: (Availability, Reliability)
    vector<Server> servers = {{5, 10}, {10, 20}, {15, 30}, {20, 40}, {25, 50}};
    
    cout << "Max Server Stability: " << serverStability(servers) << endl;
    
    return 0;
}

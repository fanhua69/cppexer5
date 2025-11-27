//
//  finditinerary.cpp
//  testcpp2
//
//  Created by hua fan on 2023-09-24.
//

#include <stdio.h>
#include <string>
#include "headers.h"
#include <algorithm>


vector<string> dfs(map<string,vector<string>> &graph, string src)
{
    vector<string> r ;
    while(graph[src].size())
    {
        string ns = graph[src].back();
        graph[src].pop_back();

        vector<string> nr = dfs(graph, ns);
        for(auto s: nr)
            r.push_back(s);
    }
    r.push_back(src);
    return r;
}


vector<string> findItinerary(vector<vector<string>> &tickets)
{
    map<string, vector<string>> graph;
    sort(tickets.begin(), tickets.end());
    reverse(tickets.begin(), tickets.end());

    for (auto v: tickets)
    {
        graph[v[0]].push_back(v[1]);
    }


    string src = "JFK";
    return dfs(graph, src);
}



void findItineraryMain2()
{
    vector<vector<string>> tickets = {{"JFK","A"}, {"JFK","b"}, {"b", "JFK"}};
    auto a = findItinerary(tickets);
    print(a);
}

//
//  dijkstra_2.cpp
//  testcpp3
//
//  Created by hua fan on 2024-11-13.
//

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>

using namespace std;

// Define a structure for the graph as an adjacency list
typedef pair<int, int> Edge; // (weight, destination)
typedef vector<vector<Edge>> Graph;

// Dijkstra's algorithm to find the shortest path from source to all other nodes
vector<int> dijkstra(const Graph &graph, int source) {
    int n = graph.size();
    vector<int> distance(n, numeric_limits<int>::max());
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    
    distance[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int currentDistance = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (currentDistance > distance[node]) continue;

        for (const auto &edge : graph[node]) {
            int weight = edge.first;
            int neighbor = edge.second;
            
            if (distance[node] + weight < distance[neighbor]) {
                distance[neighbor] = distance[node] + weight;
                pq.push({distance[neighbor], neighbor});
            }
        }
    }
    return distance;
}

int dijkstra2_main() {
    int nodes = 5;
    Graph graph(nodes);

    // Add edges (weight, destination)
    graph[0].push_back({10, 1});
    graph[0].push_back({5, 2});
    graph[1].push_back({1, 2});
    graph[1].push_back({2, 3});
    graph[2].push_back({9, 3});
    graph[2].push_back({3, 4});
    graph[3].push_back({4, 4});

    int source = 0;
    vector<int> shortestPaths = dijkstra(graph, source);

    cout << "Shortest paths from node " << source << ":\n";
    for (int i = 0; i < nodes; ++i) {
        cout << "To node " << i << " -> " << shortestPaths[i] << endl;
    }

    return 0;
}

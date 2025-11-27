//
//  findCheapestFlights.cpp
//  testcpp3
//
//  Created by hua fan on 2024-12-06.
//

#include <vector>
#include <queue>
#include <utility>
#include "print.h"

using namespace std;

template<typename T, typename Container=std::deque<T> >
class iterable_queue : public std::queue<T,Container>
{
public:
    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }
};



int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto &flight : flights)
            graph[flight[0]].push_back({flight[1], flight[2]});
        
        vector<int> cost(n, (int)(1e9));
        iterable_queue<vector<int>> qu;
        qu.push({src, 0, 0});
        
        while (!qu.empty()) {
            auto flight = qu.front();
            qu.pop();

            int node = flight[0];
            int nodeCost = flight[1];
            int stops = flight[2];

            if (stops > k) continue;

            for (auto p : graph[node]) 
            {
                int child = p.first;
                int childCost = p.second;
                if (childCost + nodeCost < cost[child]) {
                    cost[child] = childCost + nodeCost;
                    qu.push({child, cost[child], stops + 1});
                }
            }

            for(auto it = qu.begin(); it != qu.end(); it++)
            {
                auto v = *it;
                cout << "Node:" << v[0] <<", Price:" << v[1] <<", Stops:" << v[2] << ";     " << endl;
                                                                                                           }
            cout << endl << endl << endl;

        }

        return cost[dst] == (int)(1e9) ? -1 : cost[dst];
}

void findCheapestPrice_main()
{
    int n = 5;
    vector<vector<int>> f {{1, 2, 5}, {0, 3, 1}, {0, 1, 5}, {3, 1, 1}, {1, 4, 1}, {4, 2, 1}};
    int src  = 0;
    int dst = 2;
    int k = 2;

    int p = findCheapestPrice(n, f,src, dst, k );
    print(p);

    vector<int> v1 = {1,2,3};
    vector<int> v2 = v1;
    vector<pair<int,int>> v3 = {{1,2}, {3,4}, {5,6}, {7,8}};
    print(v3);

    string s = "1234";
    for(auto it = s.begin(); it!=s.end(); it++)
        auto v = *it;

    int arr[5] = {1,2,3,4,5};
    cout << "array decayed:" << std::is_same<decay<decltype(arr)>::type, int *>::value << endl;

    const string &ss = s;
    cout << typeid(std::decay<decltype(ss)>::type).name() << endl;
    cout << std::is_same_v<decltype(ss), const string&> << endl;



}

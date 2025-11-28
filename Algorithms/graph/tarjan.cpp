//
//  tarjan.cpp
//  cppexer5
//
//  Created by hua fan on 2025-11-27.
//


#include "headers_2.h"
#include <iostream>
#include <functional>
#include <queue>

using namespace std;

namespace {


vector<vector<int>> tarjan(vector<vector<int>> & g)
{
    int N = g.size();
    vector<bool> visited(N,false);
    int time = 0;
    vector<int> dfn(N,0);
    vector<int> low(N,INT_MAX);
    queue<int> st;
    
    vector<int> scc;
    vector<vector<int>> re;
    function<void(int)> dfs = [&](int u)
    {
        visited[u] = true;
        dfn[u] = time;
        low[u] = time;
        time++;
        
        for(auto v: g[u])
        {
            if(!visited[v])
            {
                dfs(v);
                low[u] = min(low[u], low[v]);
            }
            else
            {
                low[u] = min(low[u], low[v]);
            }
        }
        st.push(u);
    };
    
    for(int i = 0; i < N; i++)
    {
        if(visited[i])continue;
        
        queue<int>().swap(st);
        scc.clear();
        dfs(i);
        while(st.size())
        {
            scc.clear();
            while(low[st.front()] < st.front())
            {
                scc.push_back(st.front());
                st.pop();
            }
            scc.push_back(st.front());
            st.pop();
            re.push_back(scc);
        }
    }
    
    return re;
    
}

vector<vector<int>> tarjan_scc(const vector<vector<int>>& g)
{
    int n = g.size();
    vector<vector<int>> sccs;
    vector<int> dfn(n, -1), low(n, -1), stk;
    vector<bool> in_stk(n, false);
    int timestamp = 0;

    function<void(int)> dfs = [&](int u)
    {
        dfn[u] = low[u] = timestamp++;
        stk.push_back(u);
        in_stk[u] = true;

        for (int v : g[u])
        {
            if (dfn[v] == -1)
            {           // 没访问过
                dfs(v);
                low[u] = min(low[u], low[v]);
            }
            else if (in_stk[v])
            {        // 访问过且在栈里 → 回边
                low[u] = min(low[u], dfn[v]);
            }
        }

        // 关键：u 是当前强连通分量的根
        if (low[u] == dfn[u]) {
            vector<int> component;
            while (true) {
                int v = stk.back();
                stk.pop_back();
                in_stk[v] = false;
                component.push_back(v);
                if (v == u) break;
            }
            sccs.push_back(component);
        }
    };

    for (int i = 0; i < n; ++i) {
        if (dfn[i] == -1) {
            dfs(i);
        }
    }

    return sccs;
}


vector<vector<int>> tarjan3(vector<vector<int>> &g)
{
    vector<vector<int>> sscs;
    int N = g.size();
    vector<int> dfn(N,-1), low(N,INT_MAX);
    vector<bool> instack(N, false);
    int timestamp = 0;
    stack<int> st;
    
    function<void(int)> dfs = [&](int u)
    {
        st.push(u);
        instack[u] = true;
        dfn[u] = low[u] = timestamp++;
        
        for(auto v: g[u])
        {
            if(!dfn[v] == -1)
            {
                dfs(v);
                low[u] = min(low[u], low[v]);
            }
            else if(instack[v])
            {
                low[u] = min(low[u], dfn[v]);
            }
        }
        
        if(dfn[u] == low[u])
        {
            vector<int> ssc;
            while(st.size())
            {
                int v = st.top();
                st.pop();
                ssc.push_back(v);

                instack[v] = false;
                if(v == u)
                    break;
            }
            sscs.push_back(ssc);
        }
    };
    
    for(int i = 0; i < N; i++)
    {
        if(dfn[i] == -1)
            dfs(i);
    }
    
    return sscs;
}

}


void tarjan_main()
{
    vector<vector<int>> graph = {
        {1},    // 0
        {2,3},  // 1
        {0},    // 2
        {4},    // 3
        {5},    // 4
        {3},    // 5
        {5,7},  // 6
        {6}     // 7
    };
    
    vector<vector<int>> graph2 = {
        {1},    // 0
        {2},  // 1
        {0},    // 2
    };
    
    // 8 个节点，经典的两个环 + 一条连接边
    vector<vector<int>> graph3 = {
        {1},      // 0 → 1
        {2},      // 1 → 2
        {0},      // 2 → 0   (0-1-2 是一个环)
        {4},      // 3 → 4
        {5},      // 4 → 5
        {3},      // 5 → 3   (3-4-5 是一个环)
        {7},      // 6 → 7
        {6}       // 7 → 6   (6-7 是一个环)
        // 没有其他边
    };
    
    vector<vector<int>> g4 = {
        {1},{2},{0},{4},{5},{3},{7},{6}
    };
    
    vector<vector<int>> g5 = {
        {1},{2},{3},{4},{5},{6},{7},{5}
    };
    
    vector<vector<int>> g6 = {
        {1},
        {0}
    };
    
    vector<vector<int>> g7 = {
        {1,4},
        {2},
        {3},
        {1},
        {5},
        {6},
        {7},
        {5}
    };
    
    vector<vector<int>> counterexample = {
        {1},    // 0 → 1
        {2},    // 1 → 2
        {3},    // 2 → 3
        {1}     // 3 → 1  (形成环 1-2-3-1)
    };
    
    
    print(tarjan(counterexample));

}

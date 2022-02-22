#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
// For capacity[i][j], capacity vector stores the "residual capacity" from vertex "i" to vertex "j"
vector<vector<ll>> capacity;
vector<vector<ll>> adj;
// Although Max-Flow is calculated in "Directed Graphs", we store edges as undirected edges,
// Since For each edge, we have to consider "Reverse Edge" as well
ll bfs(int s, int t, vector<ll>& parent)
{
    // Initialise Parent of Every Node = -1 (Which means No Parent)
    fill(parent.begin(), parent.end(), -1); // Initialised!
    parent[s] = -2; // Source has no parent
    queue<pair<ll, ll>> q;
    // First will store the vertex
    // Second will store the minimum flow from "s" to this vertex
    q.push({s, INF});
    while(!q.empty())
    {
        ll cur_node = q.front().first;
        ll cur_flow = q.front().second;
        q.pop();
        for(const auto& val : adj[cur_node])
        {
            // Parent[val] == -1 denotes it is "Not Visited till now"
            // capacity[cur_node][val] denotes capacity of edge from "node" to "val"
            if(parent[val] == -1 && capacity[cur_node][val])
            {
                parent[val] = cur_node;
                ll next_flow = min(cur_flow, capacity[cur_node][val]);
                if(val == t)
                {
                    return next_flow;
                }
                q.push({val, next_flow});
            }
        }
    }
    return 0; // No Augmented Path
}
ll maxflow(int s, int t, int n)
{
    ll flow = 0;
    vector<ll> parent(n + 1); // Parent Vector
    ll new_flow = 0;
    while(new_flow = bfs(s, t, parent)) // If BFS found a augmented path, it will return Non-Zero,
    {                                     // Otherwise will return Zero(and while loop will be breaked)
        flow += new_flow;
        int cur = t;
        while(cur != s)
        {
            int par = parent[cur]; // par == parent[cur]
            capacity[par][cur] -= new_flow; // Since I go from "par" to "cur", my residual capacity
                                            // from "par" to "cur" will decrease
            capacity[cur][par] += new_flow; // And my residual capacity from "cur" to "par" will 
                                            // increase
            cur = par;
        }
    }
    return flow;
}
int main()
{
    int n, m; cin >> n >> m;
    adj.assign(n + 1, vector<ll>());
    capacity.assign(n + 1, vector<ll>(n + 1, 0));
    for (int i = 0; i < m; i++) {
        int a, b, cap; cin >> a >> b >> cap;
        adj[a].push_back(b);
        adj[b].push_back(a);
        capacity[a][b] = cap; // Although, we will assume the edges to be undirected,
                              // this doesn't mean that capacity will be the same!
        capacity[b][a] = 0; // Reverse Edge Capacity = 0
    }
    int s, t; cin >> s >> t; // Source-Target
    cout << maxflow(s, t, n);
    return 0;
}


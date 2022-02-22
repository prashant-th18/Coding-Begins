#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
vector<vector<pair<int, int>>> adj;
void dijkstra(int source, vector<int>& dist, vector<int>& parent, int nodes)
{
    dist.assign(nodes + 1, inf); // No-one is reachable from source till now
    parent.assign(nodes + 1, -1); // Parent of all nodes till now is -1
    vector<bool> marked(nodes + 1, false);
    for (int i = 0; i < n; i++) {
        int v = -1;
        for(int j = 1; j <= n; ++j)
        {
            if(!marked[j] && (v == -1 || dist[j] < dist[v]))
            {
                v = j; // We choose that node, which is not marked yet, and also whose distance is
                // less than the distance of "v" vertex
            }
            if(dist[v] == inf) break;
            marked[v] = true;
            for(const auto& [x, y] : adj[v])
            {
                // If, what I am providing you the shortest path distance is less than what you were
                // initially keeping, then change the distance to new smaller distance, and 
                // make me the parent
                if(d[v] + y < d[x])
                {
                    d[x] = d[v] + y;
                    p[x] = v;
                }
            }
        }
    }
    // Total Time Complexity -> O(n * n + m)
}
int main()
{
    int n, m; cin >> n >> m;
    adj.assign(n + 1, vector<pair<int, int>>());
    vector<int> dist, parent;
    for (int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        v[a].push_back({b, w});
        v[b].push_back({a, w});
    }
    dijkstra(1, dist, parent, n);
    return 0;
}

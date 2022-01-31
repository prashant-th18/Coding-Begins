// SSSP -> Single Source Shortest Path Using DFS [ On Trees ]
#include <bits/stdc++.h>
using namespace std;
int N = 2e5 + 1;
vector<vector<int>> adj(N); // Adjacency List
vector<bool> vis(N, false); // Visited Vector
vector<int> dis(N, 0); // Distance Vector
void SSSP(int source, int diss) // It tells ki source, Main source se dis distance prr hai
{
    vis[source] = true;
    dis[source] = diss;
    for(auto nbr : adj[source])
    {
        if(!vis[nbr])
        {
            SSSP(nbr, diss + 1);
        }
    }
}
int main()
{
    int vertices, edges; cin >> vertices >> edges;
    for (int i = 0; i < edges; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int source; cin >> source;
    SSSP(source, 0);
    for (int i = 1; i <= vertices; i++) {
        cout << i << ' ' << dis[i] << '\n';
    }
    return 0;
}

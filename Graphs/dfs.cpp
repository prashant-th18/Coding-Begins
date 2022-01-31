#include <bits/stdc++.h>
using namespace std;
int N = 2e5 + 1;
vector<vector<int>> adj(N); // Adjacency List
vector<bool> visited(N, false); // Visited Vector
// DFS -> Depth First Search
void dfs(int v) // Time Complexity -> O(N + M)
{
    visited[v] = true;
    cout << v << " --> ";
    for(int nbr : adj[v])
    {
        if(!visited[nbr])
        {
            dfs(nbr);
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
    dfs(source);
    return 0;
}
// 6 5 1 2 2 3 2 4 4 5 4 6 1

#include <bits/stdc++.h>
using namespace std;
int N = 1e5;
vector<vector<int>> adj(N); // Adjacency List
vector<int> visited(N, 0);
// DFS
void dfs(int v)
{
    visited[v] = 1;
    for(int child : adj[v])
    {
        if(visited[child] == 0)
        {
            dfs(child);
        }
    }
}
int main()
{
    int nodes, edges; cin >> nodes >> edges;
    for (int i = 0; i < edges; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int cc_count = 0;
    for(int i = 1; i <= nodes; ++i)
    {
        if(visited[i] == 0)
        {
            dfs(i);
            ++cc_count;
        }
    }
    cout << "# of CC : " << cc_count << endl;
    return 0;
}
/* 
8
7
1 5
2 5
2 8
5 6
6 8
6 4
3 7
*/

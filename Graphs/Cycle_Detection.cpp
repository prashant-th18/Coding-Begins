#include <bits/stdc++.h>
using namespace std;
int N = 2e5 + 1;
vector<vector<int>> v(N); // Adjacency List
vector<bool> vis(N, false);
// A graph will contain a cycle if there exists a "Back Edge"
// Back Edge -> A Edge which connects a node from it's ancestor(Not Parent).
bool dfs(int s, int parent)
{
    vis[s] = true;
    for(const auto& child : v[s])
    {
        if(!vis[child])
        {
            if( dfs(child, s) == true )
            {
                return true;
            }
        }
        else
        {
            if(child != parent) // Back - Edge found!
            {
                return true;
            }
        }
    }
    // No Back Edge Found
    return false;
}
int main()
{
    int vertices, edges; cin >> vertices >> edges;
    for (int i = 0; i < edges; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int source; cin >> source;
    bool cycle = dfs(source, -1); // I am assuming that I have only 1 connected component.
    if(cycle)
    {
        cout << "Graph Contains a Cycle\n";
    }
    else cout << "Graph doesn't contain a cycle";
    return 0;
}

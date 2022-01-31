#include <bits/stdc++.h>
using namespace std;
int N = 2e5 + 1;
vector<vector<int>> v(N); // Adjacency List
vector<bool> vis(N, false); // Visited Vector
vector<int> in(N, 0); // In-Time
vector<int> out(N, 0); // Out-Time
int timer = 1;
void dfs(int s)
{
    vis[s] = true;
    in[s] = timer++;
    for(int child : v[s])
    {
        if(!vis[child])
        {
            dfs(child);
        }
    }
    out[s] = timer++;
}
int main()
{
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    // We are supposing that the given graph is a tree
    // We want to solve this problem ->
    // You will have query upto 1e5. In each query, you will be given two nodes -> a, b
    // You want to tell whether one of the node lies in the subtree of another node
    dfs(1); // Precalculating....
    int q; cin >> q;
    while(q--)
    {
        int a, b; cin >> a >> b;
        // We will use in/out time concept here.
        // In time is the time when we made a "dfs" call to that node.
        // Out time is the time when that "dfs" call returns.
        // If "y" lies in the subtree of "x"
        // Then -> 
        // In-time of y must be greater than that of x
        // Out-time of y must be less than that of x
        if(in[a] < in[b] && out[a] > out[b] || in[a] > in[b] && out[a] < out[b])
        {
            cout << "True\n";
        }
        else cout << "False\n";
    }
    return 0;
}
// There's a application of In-Out Time
// If you want to know the number of vertices in a connected component ->
// Formula : (y - x + 1) / 2
// Where : 
// y -> Out-time of the vertex on which we call dfs
// x -> In-time of vertex on which we call dfs

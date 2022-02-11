// Time Complexity ->
// O(N) for each query
// Space Complexity ->
// O(N)
#include<bits/stdc++.h>
using namespace std;
vector<int> level;
vector<bool> vis;
vector<int> parent;
vector<vector<int>> v;
void dfs(int node, int depth = 0)
{
    vis[node] = true;
    level[node] = depth;
    for(const auto& val : v[node])
    {
        if(!vis[val])
        {
            parent[val] = node;
            dfs(val, depth + 1);
        }
    }
}
int main()
{
    int n, m; cin >> n >> m;
    v = vector<vector<int>>(n + 1);
    vis.assign(n + 1, false);
    parent.assign(n + 1, -1); // parent[i] is the parent of "i"
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    level.assign(n + 1, 0); // Tells about the level of node "i" from the root node
    dfs(1);
    auto lca = [&](int a, int b) -> int
    {
        // We assume that b is deeper than a from the "root node"
        if(level[a] > level[b]) swap(a, b);

        int diff = level[b] - level[a];
        // This is the difference between the levels of "a" and "b". I have to jump upwards from "b"
        // till the difference of level is zero
        while(diff > 0)
        {
            b = parent[b]; // One jump upwards
            diff--;
        }
        // Okay Now they are at the same level.
        // So it maybe possible that node "b" is now node "a".
        if(b == a)
        {
            // This means node "b" was in the subtree of node "a"
            return a; // Node "a" is the LCA 
        }
        // This means they are in different subtrees
        // Now, jump upwards from both the nodes, till you got the same parent for node "a" and "b"
        while(parent[a] != parent[b])
        {
            a = parent[a]; b = parent[b];
        }
        return parent[a]; // LCA
    };
    int q; cin >> q;
    while(q--)
    {
        int a, b; cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define sz(x) (int)x.size()
vector<vector<int>> v;
vector<vector<int>> lca;
vector<int> level;
void dfs(int node, int parent, int depth) // Parent of Root node = -1
{
    lca[node][0] = parent;
    level[node] = depth;
    for(const auto& val : v[node])
    {
        if(val != parent)
        {
            dfs(val, node, depth + 1);
        }
    }
}
void init(int n, int col)
{
    dfs(1, -1, 0); // Assuming 1 to be my Root Node
    // DP
    for(int j = 1; j < col; ++j)
    {
        // 2^j th parent
        for(int i = 1; i <= n; ++i)
        {
            int parent = lca[i][j - 1];
            if(parent != -1)
            {
                parent = lca[parent][j - 1];
                lca[i][j] = parent;
            }
        }
    }
}
int LCA(int a, int b)
{
    // b should be deeper
    if(level[a] > level[b])
    {
        swap(a, b);
    }
    int diff = level[b] - level[a];
    while(diff > 0)
    {
        // suppose diff = 13 => 1101 =>
        // make 2^3 jump => 2^2 jump => 2^0 jump
        int max_power = log2(diff);
        b = lca[b][max_power];
        diff -= (1LL << max_power);
    }
    if(a == b) return a;

    for(int i = sz(lca[0]) - 1; i >= 0; --i)
    {
        if(lca[a][i] != -1 && (lca[a][i] != lca[b][i]))
        {
            a = lca[a][i]; b = lca[b][i];
        }
    }
    return lca[a][0];
}
int dist(int n1, int n2)
{
    // Formula -> level[n1] - level[LCA] + level[n2] - level[LCA]
    return level[n1] + level[n2] - 2 * level[LCA(n1, n2)];
}
int main()
{
    int n; cin >> n;
    v = vector<vector<int>>(n + 1);
    // Taking input of Rooted Tree
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int col = log2(n) + 1;
    lca = vector<vector<int>>(n + 1, vector<int>(col + 1, -1));
    level.assign(n + 1, 0);
    init(n, col);
    // lca is initialised
    int q; cin >> q;
    while(q--)
    {
        int a, b; cin >> a >> b;
        cout << dist(a, b) << '\n';
    }
    return 0;
}

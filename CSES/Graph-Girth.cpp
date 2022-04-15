#include<bits/stdc++.h>
using namespace std;
int cnt = 0;
vector<vector<int>> v;
vector<bool> vis;
bool dfs(int node, int par, int cnt)
{
    vis[node] = true;
    for(const auto& val : v[node])
    {
        if(val == par) continue;
        else if(vis[val])
        {
            return true;
        }
        else
        {
            if(dfs(val, node, cnt + 1)) return true;
        }
    }
    return false;
}
int main()
{
    ios :: sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    v.assign(n + 1, vector<int>());
    vis.assign(n + 1, false);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 1; i <= n; ++i)
    {
        vis.assign(n + 1, false);
        cnt = 0;

    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define sz(s) (int)s.size()
vector<vector<int>> v;
vector<bool> vis;
vector<int> cycle;
bool dfs(int node, int parent = -1)
{
    vis[node] = true;
    cycle.push_back(node);
    for(int val : v[node])
    {
        if(!vis[val])
        {
            if( dfs(val, node) ) return true;
        }
        else if(val != parent)
        {
            cycle.push_back(val);
            return true;
        }
    }
    cycle.pop_back(); // No contribution
    return false;
}
int main()
{
    int n, m; cin >> n >> m;
    v = vector<vector<int>>(n + 1);
    vis.assign(n + 1, false);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
for(int i = 1; i <= n; ++i) {
    if(!vis[i] && dfs(i))
    {
        vector<int> ans;
        int same = cycle.back();
        ans.push_back(same);
        for(int j = sz(cycle) - 2; j >= 0; --j)
        {
            ans.push_back(cycle[j]);
            if(cycle[j] == same) break;
        }
        cout << sz(ans) << '\n';
        for(auto val : ans) cout << val << ' ';
        return 0;
    }
}
    cout << "IMPOSSIBLE";
    return 0;
}

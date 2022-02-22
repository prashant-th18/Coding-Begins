#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
const int MOD = 1e9 + 7;
// *-> KISS*
vector<set<int, greater<int>>> v;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> value;
set<int> dfs(int node)
{
    set<int, greater<int>> myset; myset.insert(value[node]);
    auto temp = [&]() -> void
    {
        while(sz(myset) > 20) myset.erase(*myset.rbegin());  
    };
    for(const auto& val : adj[node])
    {
        if(!vis[val])
        {
            auto t = dfs(val);
            myset.insert(all(t));
            temp();
        }
    }
    return v[node] = myset;
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    //cin >> test;
    for(int t_ = 0; t_ < test; t_++)
    {
        int n, q; cin >> n >> q;
        value.assign(n + 1, 0);
        for(int i = 1; i <= n; ++i) cin >> value[i];
        v = vector<set<int>>(n + 1);
        adj.assign(n + 1, vector<int>());
        vis.assign(n + 1, false);
        for (int i = 0; i < n - 1; i++) {
            int a, b; cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dfs(1);
        while(q--)
        {
            int v, k; cin >> v >> k;

        }
        cout << '\n';	
    }
    return 0;
}
// -> Keep It Simple Stupid!

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
// *-> KISS*
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    //cin >> test;
    for(int t_ = 0; t_ < test; t_++)
    {
        int n, m; cin >> n >> m;
        vector<vector<int>> v(n + 1);
        vector<bool> vis(n + 1, false);
        for (int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        vector<int> parent(n + 1);
        auto bfs = [&](int node) -> bool
        {
            queue<int> q; q.push(node); vis[node] = true;
            while(!q.empty())
            {
                int f = q.front(); q.pop();
                if(f == n) return true;
                for(const auto& val : v[f])
                {
                    if(!vis[val])
                    {
                        q.push(val);
                        vis[val] = true;
                        parent[val] = f;
                    }
                }
            }
            return false;
        };
        if(bfs(1))
        {
            vector<int> pos;
            for(int i = n; i != 1; i = parent[i])
            {
                pos.push_back(i);
            }
            pos.push_back(1);
            reverse(all(pos));
            cout << sz(pos) << '\n';
            for(auto val : pos) cout << val << ' ';
        }
        else
        {
            cout << "IMPOSSIBLE";
        }
    }
    return 0;
}
// -> Keep It Simple Stupid!

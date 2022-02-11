#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
const int MOD = 1e9 + 7;
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
        vector<int> in(n + 1, 0);
        for (int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            v[a].push_back(b);
            in[b]++;
        }
        queue<int> q;
        for(int i = 1; i <= n; ++i) if(in[i] == 0) q.push(i);
        vector<int> ans;
        while(!q.empty())
        {
            int ff = q.front(); q.pop();
            ans.push_back(ff);
            for(const auto& val : v[ff])
            {
                --in[val];
                if(in[val] == 0) q.push(val);
            }
        }
        if(sz(ans) != n) cout << "IMPOSSIBLE";
        else
        {
            for(auto val : ans) cout << val << ' ';
        }
        cout << '\n';
    }
    return 0;
}
// -> Keep It Simple Stupid!

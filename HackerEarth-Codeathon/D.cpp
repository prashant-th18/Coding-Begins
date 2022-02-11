#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
const int MOD = 1e9 + 7;
// *-> KISS*
vector<int> cycles;
vector<bool> vis;
vector<int> v;
void cycle(int node)
{
    vis[node] = true;
    cycles.push_back(node);
    if(!vis[v[node]])
    {
        cycle(v[node]);
    }
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    cin >> test;
    for(int t_ = 0; t_ < test; t_++)
    {
        int n; cin >> n;
        v.assign(n, 0);
        vis.assign(n, false);
        cycles.clear();
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            --v[i];
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            if(!vis[i])
            {
                cycle(i);
                for(auto val : cycles)
                {
                    ans[val] = sz(cycles) - 1;
                }
                cycles.clear();
            }
        }
        cout << accumulate(all(ans), 0LL) << '\n';
        for(auto val : ans) cout << val << ' ';
        cout << '\n';	
    }
    return 0;
}
// -> Keep It Simple Stupid!

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
const int MOD = 1e9 + 7;
// *-> KISS*
int N = 2e5, n = 0, m = 0;
vector<vector<int>> v;
vector<bool> vis;
vector<ll> dp;
vector<int> path;
ll top_down(int node)
{
    ll maxx = 0;
    vis[node] = true;
    if(dp[node] != -1) return dp[node];
    bool last = false;
    for(const auto& val : v[node])
    {
        if(val == n)
        {
            last = true; continue;
        }
        if(vis[val])
        {
            maxx = max(maxx, dp[val]);
        }
        else
        {
            maxx = max(maxx, top_down(val));
        }
    }
    if(maxx != 0)
    {
        dp[node] = 1 + maxx;
    }
    else if(last)
    {
        dp[node] = 1;
    }
    else dp[node] = 0;
    return dp[node];
}
void mypath(int node)
{
    path.push_back(node);
    if(node == n)
    {
        return;
    }
    int nn = -1, dist = 0;
    for(const auto& val : v[node])
    {
        if(dp[val] > dist)
        {
            dist = dp[val]; nn = val;
        }
    }
	if(nn == -1) nn = n;
    mypath(nn);
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    //cin >> test;
    for(int t_ = 0; t_ < test; t_++)
    {
        cin >> n >> m;
        v = vector<vector<int>>(n + 1);
        vis.assign(n + 1, false);
        dp.assign(n + 1, -1);
        for (int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            v[a].push_back(b);
        }
        if(top_down(1) > 0)
        {
            mypath(1);
            cout << sz(path) << '\n';
            for(auto val : path) cout << val << ' ';
        }
        else cout << "IMPOSSIBLE";
        cout << '\n';	
    }
    return 0;
}
// -> Keep It Simple Stupid!


#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif
// #pragma GCC optimize("O3")
// #pragma GCC target("popcnt")
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
const int MOD = 1000000007;
typedef long long ll;
typedef long double ld;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)
#define ff first
#define ss second

// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// #define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered Set */
// #define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered MultiSet */

vector<bool> vis;
vector<vector<int>> v;
vector<int> dp;
int path(int node)
{
    vis[node] = true;
    int len = -1;
    for(const auto& val : v[node])
    {
        if(!vis[val])
        {
            len = max(len, path(val));
        }
        else
        {
            len = max(len, dp[val]);
        }
    }
    return dp[node] = 1 + len;
}
// *-> KISS*
int solve() {
    freopen("longpath.in", "r", stdin);
    freopen("longpath.out", "w", stdout);
    int n, m; cin >> n >> m;
    v.assign(n + 1, vector<int>());
    vis.assign(n + 1, false);
    dp.assign(n + 1, -MOD);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
    }
    int maxx = -1;
    for(int i = 1; i <= n; ++i)
    {
        if(!vis[i])
        {
            maxx = max(maxx, path(i));
        }
        else
            maxx = max(maxx, dp[i]);
    }
    cout << maxx;
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    //cin >> TET;
    cout << fixed << setprecision(6);
    for (int i = 1; i <= TET; i++) {
#ifdef LOCAL
        cout << "##################" << '\n';
#endif
        if (solve())
        {
            break;
        }
        cout << '\n';
    }
#ifdef LOCAL
    cout << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
    return 0;
}
// -> Keep It Simple Stupid!

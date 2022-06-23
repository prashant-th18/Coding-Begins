#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif
// #pragma GCC optimize("O3")
// #pragma GCC target("popcnt")
#include "bits/stdc++.h"
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
int n;
vector<vector<int>> v;
vector<int> dp, value;
vector<bool> vis;
vector<int> ans;
int cal(int node) {
    vis[node] = true;
    int c = ((value[node] == 1) ? (1) : (-1));
    for(const auto& val : v[node]) {
        if(!vis[val]) {
            cal(val);
            c += max(0, dp[val]);
        }
    }
    return dp[node] = c;
}
void fun(int node) {
    ans[node] = dp[node];
    vis[node] = true;
    for(const auto& val : v[node]) {
        if(!vis[val]) {
            ll t1 = dp[node];
            ll t2 = dp[val];
            dp[node] -= max(0, dp[val]);
            dp[val] += max(0, dp[node]);
            fun(val);
            dp[val] -= max(0, dp[node]);
            dp[node] += max(0, dp[val]);
        }
    }
}
// *-> KISS*
int solve() {
    cin >> n;
    value.assign(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> value[i + 1];
    }
    v.assign(n + 1, vector<int>());
    dp.assign(n + 1, INT_MIN);
    vis.assign(n + 1, false);
    ans.assign(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    // Assume Root -> 1
    cal(1);
    vis.assign(n + 1, false);
    fun(1);
    for(int i = 1; i <= n; ++i) cout << ans[i] << ' ';
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool test = false;
    int TET = 1;
    if(test) cin >> TET;
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

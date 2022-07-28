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
vector<array<ll, 2>> a, dp;
void dfs(int node, int p = -1) {
    for(const auto& val : v[node]) {
        if(val != p) {
            dfs(val, node);
            dp[node][0] += max(abs(a[node][0] - a[val][0]) + dp[val][0], abs(a[node][0] - a[val][1]) + dp[val][1]);
            dp[node][1] += max(abs(a[node][1] - a[val][0]) + dp[val][0], abs(a[node][1] - a[val][1]) + dp[val][1]);
        }
    }
}
// *-> KISS*
int solve() {
    cin >> n;
    a.assign(n + 1, {0, 0});
    v.assign(n + 1, vector<int>());
    dp.assign(n + 1, {0, 0});
    for(int i = 0; i < n; ++i) {
        cin >> a[i + 1][0] >> a[i + 1][1];
    }
    for(int i = 0; i < n - 1; ++i) {
        int aa, b; cin >> aa >> b;
        v[aa].push_back(b);
        v[b].push_back(aa);
    }
    dfs(1);
    cout << max(dp[1][0], dp[1][1]);
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool test = true;
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

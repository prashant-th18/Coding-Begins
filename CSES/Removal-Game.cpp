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

// *-> KISS*
int solve() {
    int n; cin >> n;
    vector<ll> v(n), pre(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        pre[i + 1] = pre[i] + v[i];
    }
    vector<vector<ll>> dp(n, vector<ll>(n, INT_MIN));
    for(int si = 1; si <= n; ++si) {
        for(int i = 0; i <= n - si; ++i) {
            int j = i + si - 1;
            if(si <= 2) {
                ll op1 = v[i];
                ll op2 = (i + 1 < n) ? (v[i + 1]) : (INT_MIN);
                dp[i][j] = max(op1, op2);
            }
            else {
                ll op1 = v[i] + (pre[j + 1] - pre[i + 1] - dp[i + 1][j]);
                ll op2 = v[j] + (pre[j] - pre[i] - dp[i][j - 1]);
                dp[i][j] = max(op1, op2);
            }
        }
    }
    cout << dp[0][n - 1];
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

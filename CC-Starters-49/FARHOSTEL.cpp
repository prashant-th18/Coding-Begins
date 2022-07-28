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
    int n, m; cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m, 0)), b(n, vector<ll>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
        }
    }
    vector<vector<ll>> dp(n + 10, vector<ll>(m + 10, 0));
    vector<vector<ll>> dpr(n + 10, vector<ll>(m + 10, 0)), dpl(n + 10, vector<ll>(m + 10, 0));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            dpl[i + 1][j + 1] = dpl[i][j + 1] + dpl[i + 1][j] + a[i][j] - dpl[i][j];
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = m - 1; j >= 0; --j) {
            dpr[i + 1][j + 1] = dpr[i][j + 1] + dpr[i + 1][j + 2] - dpr[i][j + 2] + b[i][j];
        }
    }
    ll ans = 0;
    for(int i = n - 1; i >= 0; --i) {
        for(int j = 0; j < m; ++j) {
            dp[i][j] = dpr[i + 1][j + 1] - dpr[i][j + 1] + dpl[i + 1][j] - dpl[i][j] + dp[i + 1][j];
        }
        
    }
    ans = dp[0][0];
    {
        ll t1 = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                t1 += a[i][j];
            }
        }
        ans = max(ans, t1);
        t1 = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                t1 += b[i][j];
            }
        }
        ans = max(ans, t1);
    }
    cout << ans;
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

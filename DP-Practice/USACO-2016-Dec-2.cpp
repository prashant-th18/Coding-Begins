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
    freopen("checklist.in", "r", stdin);
    freopen("checklist.out", "w", stdout);
    int n, m; cin >> n >> m;
    vector<pair<ll, ll>> h(n), g(m);
    for (int i = 0; i < n; i++) {
        cin >> h[i][0] >> h[i][1];
    }
    for (int i = 0; i < m; i++) {
        cin >> g[i][0] >> g[i][1];
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 1e12));
    auto dis = [&](pair<ll, ll>& a, pair<ll, ll>& b) -> ll {
        return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);  
    };
    for(int i = n - 1; i >= 0; --i) {
        for(int j = m; j >= 0; --j) {
            if(i == n - 1 && j == m) dp[i][j] = 0;
            else if(i == n - 1) {
                if(j == m - 1) {
                    dp[i][j] = dis(h[i], g[j]);
                }
                else {
                    dp[i][j] = dis(g[j], g[j + 1]) + dp[i][j + 1];
                }
            }
            else {
                if(j == m) {
                    dp[i][j] = dis(h[i], h[i + 1]) + dp[i + 1][j];
                }
                else if(i == n - 2) {
                    
                }
            }
        }
    }
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

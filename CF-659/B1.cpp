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
    int n, k, l; cin >> n >> k >> l;
    vector<int> v(n + 1, 0), p(2 * k);
    for (int i = 0; i < n; i++) {
        cin >> v[i + 1];
    }
    for(int i = 0; i <= k; ++i) p[i] = i;
    for(int i = 0; i < k - 1; ++i) {
        p[i + k + 1] = k - i - 1;
    }
    vector<vector<bool>> dp(n + 2, vector<bool>(2 * k, false));
    // Base Case
    for (int i = 0; i < 2 * k; i++) {
        dp[n + 1][i] = true;
    }
    for(int i = n; i >= 0; --i) {
        for(int t = 0; t < 2 * k; ++t) {
            int ex = ((i == 0) ? (0) : (p[t]));
            if(v[i] + ex <= l) {
                dp[i][t] = dp[i + 1][(t + 1) % (2 * k)];
            }
        }
        for(int c = 0; c < 100; ++c) {
            for(int t = 2 * k - 1; t >= 0; --t) {
                int ex = ((i == 0) ? (0) : (p[t]));
                if(v[i] + ex <= l) 
                    dp[i][t] = dp[i][t] | dp[i][(t + 1) % (2 * k)];
            }
        }
    }
    bool flag = false;
    for (int i = 0; i < 2 * k; i++) {
        flag = flag | dp[0][i];
    }
    cout << (flag ? "YES" : "NO");
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
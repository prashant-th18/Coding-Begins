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
    int n, in = -1, s{}; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        s += v[i];
        if(v[i] & 1) in = i;
    }
    if(s & 1) cout << 0;
    else {
        int t = s / 2;
        vector<vector<bool>> dp(n + 1, vector<bool>(t + 1, false));
        dp[0][0] = true;
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j <= t; ++j) {
                if(j == 0) dp[i][j] = true;
                else {
                    if(dp[i - 1][j]) dp[i][j] = true;
                    if(j - v[i - 1] >= 0 && dp[i - 1][j - v[i - 1]]) dp[i][j] = true;
                }
            }
        }
        if(!dp[n][t]) cout << 0;
        else {
            if(in != -1) {
                cout << 1 << '\n' << in + 1;
            }
            else {
                pair<int, int> m = {-1, 33};
                for(int i = 0; i < n; ++i) {
                    int j = 0;
                    while(v[i]) {
                        if(v[i] & 1) {
                            if(j < m.ss) m = pair(i, j);
                            break;
                        }
                        ++j;
                        v[i] >>= 1;
                    }
                }
                cout << 1 << '\n' << m.ff + 1;
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

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
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    if(n & 1) {
        ll ans = 0;
        for(int i = 1; i < n - 1; i += 2) {
            ll maxx = max(v[i - 1], v[i + 1]);
            ll diff = max(maxx - v[i] + 1, 0LL);
            ans += diff;
        }
        cout << ans;
    }
    else {
        ll very = 1000000000000000LL;
        vector<array<ll, 2>> dp(n + 10, {very, very});
        for(int i = n - 2; i >= 1; --i) {
            ll maxx = max(v[i - 1], v[i + 1]);
            ll diff = max(maxx - v[i] + 1, 0LL);
            if(i == n - 2 || i == n - 3) {
                dp[i][0] = diff;
                dp[i][1] = diff;
            }
            else {
                dp[i][0] = diff + dp[i + 2][0];
                dp[i][1] = min(dp[i + 2][1] + diff, diff + dp[i + 3][0]);
            }
        }
        cout << min({dp[1][0], dp[1][1], dp[2][0]});
    }
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

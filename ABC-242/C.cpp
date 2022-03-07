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
#define MOD 998244353
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
int N = 1e6 + 10;
vector<vector<ll>> dp(N, vector<ll>(9)); // x -> x - 1
// *-> KISS*
int solve() {
    for(int i = 0; i < 9; ++i)
    {
        dp[0][i] = 1;
    }
    for(int i = 1; i < N; ++i)
    {
        for(int j = 0; j < 9; ++j)
        {
            ll same = dp[i - 1][j];
            ll down = ((j - 1 >= 0) ? (dp[i - 1][j - 1]) : (0));
            ll up = ((j + 1 < 9) ? (dp[i - 1][j + 1]) : (0));
            dp[i][j] = ((same + down) % MOD + up) % MOD;
        }
    }
    int n; cin >> n;
    ll ans = 0;
    for(int i = 0; i < 9; ++i) ans = (ans + dp[n - 1][i]) % MOD;
    cout << ans;
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

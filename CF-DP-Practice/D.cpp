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

// *-> KISS*
int solve() {
    freopen("king2.in", "r", stdin);
    freopen("king2.out", "w", stdout);
    int n = 8;
    vector<vector<int>> v(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    vector<vector<ll>> dp(n, vector<ll>(n, INT_MAX));
    dp[n - 1][0] = 0;
    for(int i = n - 1; i >= 0; --i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(i - 1 >= 0)
            {
                if(j + 1 < n) dp[i - 1][j + 1] = min(dp[i - 1][j + 1], dp[i][j] + v[i - 1][j + 1]);
                dp[i - 1][j] = min(dp[i - 1][j], dp[i][j] + v[i - 1][j]);
            }
            if(j + 1 < n)
            {
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + v[i][j + 1]);
            }
        }
    }
    cout << dp[0][n - 1];
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

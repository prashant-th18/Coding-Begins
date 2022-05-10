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
    int n; cin >> n;
    vector<vector<int>> v(n), dp(n);
    for (int i = 0; i < n; i++) {
        vector<int> temp(i + 1, INT_MIN);
        dp[i] = temp;
        for (int j = 0; j < i + 1; j++) {
            cin >> temp[j];
        }
        v[i] = temp;
        if(i == n - 1) dp[i] = temp;
    }
    for(int i = n - 1; i >= 1; --i)
    {
        for(int j = 0; j < sz(v[i]); ++j)
        {
            if(j - 1 >= 0)
            {
                dp[i - 1][j - 1] = max(dp[i - 1][j - 1], dp[i][j] + v[i - 1][j - 1]);
            }
            if(j != sz(v[i]) - 1)
            {
                dp[i - 1][j] = max(dp[i - 1][j], dp[i][j] + v[i - 1][j]);
            }
        }
    }
    cout << dp[0][0];
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

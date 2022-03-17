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
    ll n, c; cin >> n >> c;
    vector<ll> a(n - 1);
    for(int i = 0; i < n - 1; ++i) { 
        cin >> a[i]; 
    }
    vector<ll> b(n - 1);
    for(int i = 0; i < n - 1; ++i) { 
        cin >> b[i]; 
    }
    vector<array<ll, 2>> dp(n, {0, 0}); // Stairs ,,,, Elevators
    for(int i = 1; i < n; ++i)
    {
        if(i == 1)
        {
            // Base Case
            dp[i][0] = a[i - 1];
            dp[i][1] = c + b[i - 1];
        }
        else
        {
            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + a[i - 1];
            dp[i][1] = min(dp[i - 1][0] + c, dp[i - 1][1]) + b[i - 1];
            // DP State ->
            // What is the minimum cost to reach the ith floor from the 0th floor given the condition 
            // that, from "i - 1"th to "ith" floor, we have used {Stairs or Elevators}
        }
    }
    for (int i = 0; i < n; i++) {
        cout << min(dp[i][0], dp[i][1]) << ' ';
    }
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

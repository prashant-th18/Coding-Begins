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

const int N = 3e6;
vector<ll> dp(N, 0);
ll mul(ll a, ll b) {
    return a * b % MOD;
}
ll add(ll a, ll b) {
    return (a + b) % MOD;
}
void init() {
    dp[0] = dp[1] = dp[2] = 0;
    dp[3] = dp[4] = 4;
    for(int i = 5; i < N; ++i) {
        ll op1 = add(mul(2, dp[i - 2]), dp[i - 1]);
        ll op2 = add(4, add(dp[i - 2], mul(4, add(dp[i - 3], dp[i - 4])))); // Choosing i
        dp[i] = max(op1, op2);
    }
}
// *-> KISS*
int solve() {
    int n; cin >> n;
    cout << dp[n];
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool test = true;
    int TET = 1;
    if(test) cin >> TET;
    cout << fixed << setprecision(6);
    init();
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

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
ll binexp(ll base, ll power)
{
    ll res = 1;
    while(power)
    {
        if(power & 1) res = res * base % MOD;
        power >>= 1;
        base = base * base % MOD;
    }
    return res;
}
// *-> KISS*
int solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<ll> dp(sz(s) + 1, 0);
    for(int i = 0; i <= n - 1; ++i)
    {
        dp[i + 1] = dp[i] + (i + 1) * (s[i] - '0');
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll temp = 0;
        if(dp[n - i] & 1)
        {
            temp = binexp(2, i);
        }
        ans = (ans + temp) % MOD;
    }
    cout << ans;
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    cin >> TET;
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

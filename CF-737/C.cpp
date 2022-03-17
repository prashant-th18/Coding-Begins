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
#define MOD 1000000007
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
    base %= MOD;
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
    ll n, k; cin >> n >> k;
    if(k == 0)
    {
        cout << 1; return 0;
    }
    ll g = (binexp(2, n - 1) - 1 + MOD) % MOD;
    ll gd = (binexp(2, n) - g + MOD) % MOD;
    vector<ll> f(k);
    for (int i = 0; i < k - 1; i++) {
        f[i] = binexp(binexp(2, k - i - 1), n) % MOD;
        if(n & 1) f[i] = f[i] * g % MOD;
    }
    f[k - 1] = ((n & 1) ? (g) : (1));
    ll sum {};
    for (int i = 0; i < k; i++) {
        ll fi = ((n & 1) ? (binexp(gd, i)) : (binexp(g, i)));
        sum = (sum + (fi * f[i]) % MOD) % MOD;
    }
    if(n & 1)
    {
        ll temp = binexp(binexp(2, k), n);
        sum = (temp - sum + MOD) % MOD;
    }
    else
    {
        sum = (sum + binexp(g, k)) % MOD;
    }
    cout << sum;
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

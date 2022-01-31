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

// *-> KISS*
int solve() {
    ll x, k; cin >> x >> k;
    if(x == 0) 
    {
        cout << 0; return 0;    
    }
    auto binexp = [&](ll base, ll power) -> ll
    {
        ll res = 1;
        while(power)
        {
            if(power & 1)
            {
                res = res * base % MOD;
            }
            power >>= 1;
            base = base * base % MOD;
        }
        return res;
    };
    auto modinv = [&](ll num) -> ll
    {
        // a^-1 % m == a ^ (m - 2) % m
        return binexp(num, MOD - 2) % MOD;
    };
    ll uplast = x % MOD * binexp(2LL, k) % MOD; // If i will not take modulo of x, then overflow may occur.
    ll total = (binexp(2, k) - 1 + MOD) % MOD + 1;
    ll down = (uplast - total + MOD) % MOD;
    ll sum1 = (uplast * (uplast + 1) % MOD) * modinv(2) % MOD;
    ll sum2 = (down * (down + 1) % MOD) * modinv(2) % MOD;
    ll sum = (sum1 - sum2 + MOD) % MOD;
    sum = sum * 2 % MOD;
    sum = sum * modinv(total) % MOD;
    cout << sum;
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
}
// -> Keep It Simple Stupid!

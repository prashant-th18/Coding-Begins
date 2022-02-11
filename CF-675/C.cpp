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
const int N = 2e5;
// *-> KISS*
int solve() {
    auto binexp = [&](ll base, ll power) -> ll
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
    };
    vector<ll> v(N);
    for(ll i = 0; i < N; ++i)
    {
        ll tt = (i + 1) * binexp(10LL, i) % MOD; // (i + 1) * binexp(10LL, i) + v[i - 1]
        if(i != 0)
        {
            tt = (tt + v[i - 1]) % MOD;
        }
        v[i] = tt;
    }
    string s; cin >> s; int n = sz(s);
    if(n <= 2)
    {
        if(n == 1) cout << 0;
        else cout << (s[0] - '0') + (s[1] - '0');
        return 0;
    }
    ll cnt = 0;
    ll inv = binexp(2, MOD - 2);
    for(int i = 0; i < n; ++i)
    {
        ll dig = s[i] - '0';
        ll temp = (i * (i + 1)) % MOD * inv % MOD;
        temp = temp * binexp(10, sz(s) - i - 1) % MOD;
        temp = temp * dig % MOD;
        ll right = 0;
        if(i != n - 1)
        {
            right = v[n - i - 2] * dig % MOD;
        }
        temp = (temp + right) % MOD;
        cnt = (cnt + temp) % MOD;
    }
    cout << cnt;
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

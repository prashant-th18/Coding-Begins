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

template<typename T>
T binexp(T a, T b) {
    T ans = 1;
    while (b) {
        if (b & 1) {
            ans = 1LL * ans * a % MOD;
        }
        a = 1LL * a * a % MOD;
        b >>= 1;
    }
    return ans;
}
ll mul(ll a, ll b)
{
    return a % MOD * (b % MOD) % MOD;
}
ll sub(ll a, ll b)
{
    a %= MOD; b %= MOD;
    return (a - b + MOD) % MOD;
}
ll add(ll a, ll b)
{
    a %= MOD;
    b %= MOD;
    return (a + b) % MOD;
}
// *-> KISS*
int solve() {
    // https://codeforces.com/contest/1422/problem/C => BUT in place of "Substring", it may work for "Subsequence"
    string s; cin >> s;
    ll ans = 0;
    int n = sz(s);
    for(ll i = 0; i < n; ++i)
    {
        ll outer = (s[i] - '0');
        ll t = n - 1 - i;
        ll p = binexp(11LL, t), two = binexp(2LL, i), ten = binexp(10LL, t);
        p = mul(p, two);
        p = sub(p, ten);
        outer = mul(outer, p);
        ans = add(ans, outer);
    }
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

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
const long long MOD = 998244353;
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

const int N = 1e6;
vector<ll> fact(N, 1);
void sub(ll &ans, ll temp) {
    ans = (ans - temp + MOD) % MOD;
}
void add(ll &ans, ll temp) {
    ans = (ans + temp) % MOD;
}
ll binexp(ll base, ll power) {
    ll res = 1;
    while(power) {
        if(power & 1) {
            res = res * base % MOD;
        }
        base = base * base % MOD;
        power >>= 1;
    }
    return res;
}
ll inv(ll num) {
    return binexp(num, MOD - 2);
}
ll ncr(ll a, ll b) {
    if(b > a) return 0;
    return (fact[a] * inv(fact[b]) % MOD * inv(fact[a - b]) % MOD);
}
// *-> KISS*
int solve() {
    ll n, k, ans {}; cin >> n >> k;
    multiset<array<int, 2>> st;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        st.insert({a, -1});
        st.insert({b, 1});
    }
    int cnt = 0;
    for(auto [x, y] : st) {
        if(y == -1) {
            sub(ans, ncr(cnt, k));
            ++cnt;
            add(ans, ncr(cnt, k));
        }
        else --cnt;
    }
    cout << ans;
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    //cin >> TET;
    for(ll i = 2; i < N; ++i) {
        fact[i] = i * fact[i - 1] % MOD;
    }
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

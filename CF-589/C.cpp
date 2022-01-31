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

int N = 1e6 + 10;

#ifdef LOCAL
#define debug(x) cout << '\n' << "----------------" << '\n' << #x << " : "; _print(x); cout << '\n' << "-------------" << '\n';
#else
#define debug(x)
#endif

template <typename T> void _print(vector <T> v) { cout << "[ "; for (auto myval : v) cout << myval << " "; cout << "]"; }
template <typename T1, typename T2> void _print(vector <T1, T2> v) { cout << "[ "; for (auto myval : v) cout << myval.ff << ' ' << myval.ss << " "; cout << "]"; }
template <typename T> void _print(set <T> v) { cout << "[ "; for (auto myval : v) cout << myval << " "; cout << "]"; }
template <typename T1, typename T2> void _print(map<T1, T2> v) { cout << "[ "; for (auto myval : v) cout << myval.ff << ' ' << myval.ss << " "; cout << "]"; }
void _print(int a) {cout << a;}
void _print(ll a) {cout << a;}
void _print(char a) {cout << a;}
void _print(string a) {cout << a;}
void _print(double a) {cout << a;}

// *-> KISS*
int solve() {
    ll x, n; cin >> x >> n;
    vector<ll> fact;
    vector<ll> primes;
    vector<bool> pr(N, false);
    for(ll i = 2; i < N; ++i)
    {
        if(!pr[i])
        {
            primes.push_back(i);
            for(ll j = i * i; j < N; j += i)
            {
                pr[i] = true;
            }
        }
    }
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
    for(ll i = 0; i < sz(primes); ++i)
    {
        int c = 0;
        while(x % primes[i] == 0)
        {
            ++c; x /= primes[i];
        }
        if(c != 0) fact.push_back(primes[i]);
    }
    if(x != 1) fact.push_back(x);
    ll ans = 1;
    for(ll i = 0; i < sz(fact); ++i)
    {
        ll num = 1;
        vector<pair<ll, ll>> store;
        while(num <= n / fact[i])
        {
            num *= fact[i];
            ll tt = n / num;
            store.push_back({num, tt});
        }
        ll pre = 0;
        while(sz(store) != 0)
        {
            ll t1 = store.back().ss;
            ans = ans * binexp(store.back().ff, t1 - pre) % MOD;
            pre = t1;
            store.pop_back();
        }
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
}
// -> Keep It Simple Stupid!

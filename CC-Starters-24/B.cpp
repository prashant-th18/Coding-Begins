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
int N = 1e6 + 1;
vector<ll> primes;
vector<bool> pr(N, true);

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
    auto binexp = [&](ll base, ll power) -> ll
    {
        ll res = 1;
        while(power)
        {
            if(power & 1) res *= base;
            power >>= 1;
            base *= base;
        }
        return res;
    };
    ll x, a, b; cin >> x >> a >> b;
    if(x % a != 0) cout << -1;
    else
    {
        ll num = b * (x / a);
        ll remain = num;
        ll s = 1;
        for(auto val : primes)
        {
            if(val * val > num)
            {
                break;
            }
            ll c = 0;
            while(num % val == 0)
            {
                num /= val; ++c;
            }
            ll temp = binexp(val, c + 1);
            s *= (temp - 1) / (val - 1);
        }
        if(num != 1)
        {
            s *= (binexp(num, 2) - 1) / (num - 1);
        }
        if(s != x) cout << -1;
        else
        {
            cout << remain;
        }
    }
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    cin >> TET;
    primes.push_back(2);
    for(ll i = 4; i < N; i += 2) pr[i] = false;
    for(ll i = 3; i < N; i += 2)
    {
        if(pr[i])
        {
            primes.push_back(i);
            for(ll j = i * i; j < N; j += 2 * i) pr[j] = false;
        }
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
}
// -> Keep It Simple Stupid!

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

template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};
template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
// use -> auto gcd = y_combinator([](auto gcd, int a, int b) -> int { return b == 0 ? a : gcd(b, a % b);});

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
vector<ll> fact(6000, 0);
// *-> KISS*
int solve() {
    auto inv = [&](ll num) -> ll
    {
        ll power = MOD - 2, res = 1;
        num %= MOD;
        while(power)
        {
            if(power & 1)
            {
                res = res * num % MOD;
            }
            power >>= 1;
            num = num * num % MOD;
        }
        return res % MOD;
    };
    auto ncr = [&](ll n, ll r) -> ll
    {
        n %= MOD;
        if(r > n) return 0;
        if(r == n || r == 0) return 1;
        return fact[n] % MOD * inv(fact[n - r]) % MOD * inv(fact[r]) % MOD;
    };
    ll n, k; cin >> n >> k;
    vector<vector<ll>> v(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    ll cnt = 0;
    auto fun = y_combinator([&](auto f, ll node, ll parent = -1) -> void
    {
         vector<vector<ll>> depth(5001);
         auto mad = y_combinator([&](auto ff, ll nodee, ll p = -1, int d = 0) -> ll
         {
                ll s = 0;
                for(const auto& val : v[nodee])
                {
                    if(val != p)
                    {
                        s += (ff(val, nodee, d + 1));
                    }
                }
                if(s != 0 && p != -1)
                {
                    depth[d + 1].push_back(s);
                }
                else if(p == -1 && s != 0)
                {
                    depth[1].push_back(sz(v[nodee]));
                }
                return 1;
         });
         mad(node);
         if(sz(depth[1]) != 0){
             cnt = (cnt + ncr(depth[1][0], k) % MOD) % MOD;
         }
         for(int i = 2; i < sz(depth); ++i)
         {
             if(sz(depth[i]) < k) continue;
             ll res = 1;
             for(int j = 0; j < sz(depth[i]); ++j)
             {
                 res = res * depth[i][j] % MOD;
             }
             cnt = (cnt + res) % MOD;
         }
         for(auto val : v[node])
         {
             if(val != parent)
             {
                 f(val, node);
             }
         }
    });
    fun(1);
    cout << cnt % MOD;
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    fact[0] = fact[1] = 1;
    for(ll i = 2; i < sz(fact); ++i)
    {
        fact[i] = i * fact[i - 1] % MOD;
    }
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

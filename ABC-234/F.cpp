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
#ifdef LOCAL
#define debug(x) cout << '\n' << "----------------" << '\n' << #x << " : "; _print(x); cout << '\n' << "-------------" << '\n';
#else
#define debug(x)
#endif

// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// #define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered Set */
// #define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered MultiSet */
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
    ll p = 998244353;
    int n = 1e6;
    vector<ll> fact(n);
    fact[0] = fact[1] = 1;
    for(ll i = 2; i < n; ++i)
    {
        fact[i] = i * fact[i - 1] % p;
    }
    
    auto binexp = [&](ll base, ll power)
    {
      ll res = 1;
      while(power)
      {
          if(power & 1)
          {
              res = res * base % p;
          }
            base = base * base % p;
            power >>= 1;
      }
      return res;
    };
    auto modinv = [&](ll nn, ll p = 998244353)
    {
        return binexp(nn, p - 2);
    };


    string s; cin >> s;
    map<char, int> mp;
    for (int i = 0; i < sz(s); i++) {
        mp[s[i]]++;
    }
    ll cnt = 0;
    vector<int> v;
    for(const auto& val : mp)
    {
        v.push_back(val.ss);
    }
    vector<ll> ever(sz(v));
    function<void(ll size, ll index)> f = [&](ll size, ll index) -> void
    {
        if(index == sz(v) - 1)
        {
            ll ss = size;
            for(int i = 0; i <= v[index]; ++i)
            {
                ever[index] = i;
                ss += i;
                if(ss == 0) continue;
                else
                {
                    // fact[ss] * inv[fact[ever[0]]] % p
                    ll anss = fact[ss];
                    for(int j = 0; j < sz(ever); ++j)
                    {
                        anss = (anss % p * modinv(fact[ever[j]]) % p) % p;
                    }
                    cnt = (cnt % p + anss % p) % p;
                }
                ss = size;
            }
        }
        else
        {
            for(int i = 0; i <= v[index]; ++i)
            {
                ever[index] = i;
                f(size + i, index + 1);
            }
        }
    };
    f(0, 0);
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

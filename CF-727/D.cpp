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
struct comp
{
  bool operator() (const pair<ll, ll>& a, const pair<ll, ll>& b) const
  {
      if(a.ss != b.ss)
      {
          return a.ss < b.ss;
      }
      return a.ff < b.ff;
  }
};
int solve() {
    ll n, sum = 0; cin >> n;
    multiset<pair<ll, ll>, comp> mp;
    vector<pair<ll, ll>> v(n);
    for (int i = 0; i < n; i++) {
        ll tt1, tt2; cin >> tt1 >> tt2;
        v[i] = pair(tt1, tt2);
        sum += tt1;
    }
    ll r = 0, crt = 0;
    for (int i = 0; i < n; i++) {
        if(v[i].ss >= sum)
        {
            r += v[i].ff;
            crt += (2 * v[i].ff);
        }
        else
        {
            mp.insert(v[i]);
        }
    }
    while(!mp.empty())
    {
        auto it = mp.begin();
        ll req = (*it).second;
        if(r >= req)
        {
            crt += (*it).first;
            r += (*it).first;
            mp.erase(it);
        }
        else
        {
            req = req - r;
            while(req != 0)
            {
                auto last = mp.end(); --last;
                pair<ll, ll> z = *last;
                ll temp = z.first;
                ll minn = min(temp, req);
                crt += (2 * minn);
                r += minn; req -= minn;
                mp.erase(last);
                temp -= minn;
                if(temp != 0) mp.insert(pair(temp, z.second));                
            }
        }
    }
    cout << crt;
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
        if(solve())
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

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

inline ll nxt() { ll _; cin >> _; return _; }

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
    ll n, k, x; cin >> n >> k >> x;
    string s; cin >> s;
    ll ccnt = 0;
    vector<ll> v;
    for (int i = 0; i < n; i++) {
        if(s[i] == 'a')
        {
            if(ccnt != 0) v.push_back(ccnt);
            ccnt = 0;
        }
        else
        {
            ++ccnt;
        }
    }
    if(ccnt != 0) v.push_back(ccnt);
    for (int i = 0; i < sz(v); i++) {
        v[i] *= k; ++v[i];
    }
    deque<ll> help;
    --x;
    // Let's Do it!
    // Overflow is the main thing for me
    for (int i = 0; i < sz(v); i++) {
        bool flag = false;
        ll z = x, cnt = 1;
        for(int j = i + 1; j < sz(v); ++j)
        {
           if(z / v[j] == 0)
           {
               z = 0;
               flag = true; break;
           }
           else cnt *= v[j], z /= v[j];
        }
        help.push_back(z);
        x -= cnt * z;
    }
    bool star = false;
    int kk = 0;
    for(int i = 0; i < n; ++i)
    {
        if(s[i] == '*')
        {
            if(!star)
            {
                star = true;
                for(int j = 0; j < help[kk]; ++j)
                {
                    cout << 'b';
                }
                ++kk;
            }
        }
        else
        {
            star = false;
            cout << s[i];
        }
    }
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
}
// -> Keep It Simple Stupid!

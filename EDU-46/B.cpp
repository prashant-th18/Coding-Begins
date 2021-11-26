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
#define debug(x) cout << "----------------" << endl << #x << " : "; _print(x); cout << "-------------" << '\n';
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
int N = 1e6;
vector<ll> v(N);
int solve() {
    // Simple iteration + Prefix Sum
    ll n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<ll> lit(n + 2), dim(n + 2);
    for (int i = 0; i <= n; i++) {
        if(i == n)
        {
            if(!(i & 1))
            {
                lit[i + 1] = lit[i] + (m - v[i - 1]);
                dim[i + 1] = dim[i];
            }
            else
            {
                dim[i + 1] = dim[i] + (m - v[i - 1]);
                lit[i + 1] = lit[i];
            }
            break;
        }
        if(!(i & 1))
        {
            ll kk = 0;
            if(i != 0) kk = v[i - 1];
            lit[i + 1] = lit[i] + v[i] - kk;
            dim[i + 1] = dim[i];
        }
        else
        {
            lit[i + 1] = lit[i];
            dim[i + 1] = dim[i] + (v[i] - v[i - 1]);
        }
    }
    ll maxx = lit[n + 1];
    // Now go to every point and first think whether it is lit or dim
    for (int i = 0; i <= n; i++) {
        if(i == n)
        {
            maxx = max(maxx, lit[i] + (m - v[i - 1] - 1));
            continue;
        }
        if(!(i & 1))
        {
            // Okay so is se piche khi pr point lga dete hai
            if(i == 0)
            {
                if(v[i] - 1 == 0)
                {
                    continue;
                }
                else
                {
                    ll temp = 0;
                    temp += (v[i] - 1);
                    temp += dim[n + 1] - dim[i + 1];
                    maxx = max(maxx, temp);
                }
            }
            else
            {
                if(v[i] - 1 == v[i - 1]) continue;
                else
                {
                    maxx = max(lit[i + 1] - 1 + (dim[n + 1] - dim[i + 1]), maxx);
                }
            }
        }
        else
        {
            maxx = max(maxx, lit[i] + (v[i] - v[i - 1] - 1) + dim[n + 1] - dim[i + 1]);
        }
    }
    cout << maxx;
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    //cin >> TET;
    for (int i = 1; i <= TET; i++) {
        if (solve()) {
            break;
        }
        #ifdef LOCAL
            cout << '\n' << "##################";
        #endif
        cout << '\n';
    }
    #ifdef LOCAL
        cout << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}
// -> Keep It Simple Stupid!

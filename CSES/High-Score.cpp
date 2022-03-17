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

struct edge {
    ll a, b, c;  
};
vector<vector<ll>> v, t;
vector<bool> vis;
map<int, bool> mp;
// *-> KISS*
int solve() {
    ll n, m; cin >> n >> m;
    // Opposite of Negative Cycle (Bellman Ford Algo)
    vector<edge> e(m);
    v.assign(n + 1, vector<ll>());
    t = v;
    vis.assign(n + 1, false);
    for (int i = 0; i < m; i++) {
        ll a, b, c; cin >> a >> b >> c;
        e[i] = {a, b, c};
        v[a].push_back(b);
        t[b].push_back(a);
    }
    vector<ll> dist(n + 1, -1e18);
    vector<ll> par(n + 1, -1);
    int x = -1;
    dist[1] = 0;
    for(int i = 0; i < n; ++i)
    {
        x = -1;
        for (int j = 0; j < m; j++) {
            if(dist[e[j].a] > -1e18)
            {
                ll ndis = dist[e[j].a] + e[j].c;
                if(dist[e[j].b] < ndis)
                {
                    dist[e[j].b] = ndis;
                    par[e[j].b] = e[j].a;
                    x = e[j].b;
                }
            }
        }
    }
    if(x != -1)
    {
        for (int i = 0; i < n; i++) {
            mp[x] = true;
            x = par[x];
        }
        mp[x] = true;
        bool flag = dfs(n, mp[n]);
        if(flag) cout << -1;
        else cout << dist[n];
    }
    else
    {
        cout << dist[n];
    }
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
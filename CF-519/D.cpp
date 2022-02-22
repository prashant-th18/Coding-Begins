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

template <typename T> void _print(vector <T> v) { cout << "[ "; for (auto myval : v) cout << myval << " "; cout << "]"; }
template <typename T1, typename T2> void _print(vector <T1, T2> v) { cout << "[ "; for (auto myval : v) cout << myval.ff << ' ' << myval.ss << " "; cout << "]"; }
template <typename T> void _print(set <T> v) { cout << "[ "; for (auto myval : v) cout << myval << " "; cout << "]"; }
template <typename T1, typename T2> void _print(map<T1, T2> v) { cout << "[ "; for (auto myval : v) cout << myval.ff << ' ' << myval.ss << " "; cout << "]"; }
void _print(int a) {cout << a;}
void _print(ll a) {cout << a;}
void _print(char a) {cout << a;}
void _print(string a) {cout << a;}
void _print(double a) {cout << a;}

// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// #define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered Set */
// #define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered MultiSet */
vector<vector<int>> v;
vector<vector<int>> t;
vector<bool> vis;
vector<int> order;
void get_order(int node)
{
    vis[node] = true;
    for(const auto& val : v[node])
    {
        if(!vis[val]) get_order(val);
    }
    order.push_back(node);
}
ll dfs(int node, ll k)
{
    vis[node] = true;
    ll temp = 0;
    for(const auto& val : t[node])
    {
        if(!vis[val])
        {
            temp += dfs(val, k + 1);
        }
    }
    return temp + k;
}
// *-> KISS*
int solve() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> mpairs;
    for (int i = 0; i < m; i++) {
        vector<int> temp(n);
        for (int &val : temp) {
            cin >> val;
        }
        for (int j = 1; j < n; j++) {
            mpairs.push_back(pair(temp[j - 1], temp[j]));
        }
    }
    vector<pair<int, int>> pairs;
    sort(mpairs.begin(), mpairs.end());
    for (int i = 0; i < sz(mpairs); i++) {
        int j = i;
        int x = mpairs[i].ff, y = mpairs[i].ss;
        while(j < sz(mpairs))
        {
            if(mpairs[j].ff == x && mpairs[j].ss == y) ++j;
            else break;
        }
        if(j - i == m) pairs.push_back(mpairs[i]);
        i = j - 1;
    }
    v.assign(n + 1, vector<int>());
    t.assign(n + 1, vector<int>());
    vis.assign(n + 1, false);
    for(auto [x, y] : pairs)
    {
        v[x].push_back(y);
        t[y].push_back(x);
    }
    for(int i = 1; i <= n; ++i)
    {
        if(!vis[i]) get_order(i);
    }
    vis.assign(n + 1, false);
    ll ans = 0;
    debug(order);
    for(int i = 0; i < sz(order); ++i)
    {
        ans += dfs(order[i], 0LL);
    }
    cout << ans + n;
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

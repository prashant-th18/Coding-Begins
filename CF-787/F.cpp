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
const int MOD = 1000000007;
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

int x, y; ///////// source, dest
vector<int> par, p; // p -> path
vector<vector<int>> v;
vector<bool> vis, pres, things;
bool path(int node, int ny) {
    vis[node] = true;
    if(node == ny) return true;
    for(const auto& val : v[node]) {
        if(!vis[val]) {
            par[val] = node;
            if(path(val, ny)) return true;
        }
    }
    return false;
}
ll dfs(int node) {
    vis[node] = true;
    ll c = 0;
    for(const auto& val : v[node]) {
        if(!vis[val] && !pres[val]) {
            c += dfs(val);
        }
    }
    if(c != 0) ++c;
    else if(things[node]) c = 1;
    return c;
}
// *-> KISS*
int solve() {
    int n, k; cin >> n >> k;
    cin >> x >> y;
    things.assign(n + 1, false);
    par.assign(n + 1, 0);
    vis.assign(n + 1, false);
    v.assign(n + 1, vector<int>());
    pres.assign(n + 1, false);
    p.clear();
    for (int i = 0; i < k; i++) {
        int tt; cin >> tt;
        things[tt] = true;
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    path(x, y);
    {
        for(int i = y; i != x; i = par[i]) {
            p.push_back(i);
            pres[i] = true;
        }
        p.push_back(x);
        pres[x] = true;
        reverse(all(p));
        vis.assign(n + 1, false);
    }
    ll ans = 0;
    for(int i = 0; i < sz(p); ++i) {
        for(const auto& val : v[p[i]]) {
            if(!vis[val] && !pres[val]) {
                ll t = dfs(val);
                ans += 2 * t;
            }
        }
        vis[p[i]] = true;
    }
    ans += (sz(p) - 1);
    cout << ans;
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
    return 0;
}
// -> Keep It Simple Stupid!

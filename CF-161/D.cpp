#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif
// #pragma GCC optimize("O3")
// #pragma GCC target("popcnt")
#include "bits/stdc++.h"
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

int n, m, k, timer = 0;
vector<set<int>> v;
vector<bool> vis;
vector<int> in, low, par;
void dfs(int node, int p) {
    vis[node] = true;
    in[node] = low[node] = timer++;
    vector<int> clear;
    for(auto val : v[node]) {
        if(val == p) continue;
        if(vis[val]) {
            // Back-edge
            low[node] = min(low[node], in[val]);
        }
        else {
            dfs(val, node);
            int lval = low[val];
            if(low[val] > low[node]) {
                // Bridge
                clear.push_back(val);
            }
            low[node] = min(low[node], lval);
        }
    }
    for(auto val : clear) {
        v[node].erase(val);
        v[val].erase(node);
    }
}
map<int, int> mp;
int fun(int node, int p = -1) {
    vis[node] = true;
    par[node] = p;
    mp[node] = timer++;
    for(auto val : v[node]) {
        if(!vis[val]) {
            return fun(val, node);
        }
    }
    int mini = INT_MAX, t = -1;
    for(auto val : v[node]) {
        if(mp[val] < mini) {
            mini = mp[val];
            t = val;
        }
    }
    par[t] = node;
    return t;
}
// *-> KISS*
int solve() {
    cin >> n >> m >> k;
    v.assign(n + 1, set<int>());
    vis.assign(n + 1, false);
    in.assign(n + 1, 0);
    low.assign(n + 1, 0);
    par.assign(n + 1, -1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        v[a].insert(b);
        v[b].insert(a);
    }
    dfs(1, -1);
    vis.assign(n + 1, false);
    timer = 0;
    int node = 0;
    for(int i = 1; i <= n; ++i) {
        if(sz(v[i]) >= 2) {
            node = i;
            break;
        }
    }
    node = fun(node);
    vector<int> t;
    int temp = node;
    assert(temp >= 1);
    while(par[temp] != node) {
        t.push_back(temp);
        temp = par[temp];
    }
    t.push_back(temp);
    cout << sz(t) << '\n';
    for(auto val : t) cout << val << ' ';
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool test = false;
    int TET = 1;
    if(test) cin >> TET;
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

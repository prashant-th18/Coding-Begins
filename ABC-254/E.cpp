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

vector<vector<int>> v;
vector<bool> vis;
int bfs(int node, int k) {
    int res = 0;
    queue<pair<int, int>> q;
    q.push({node, 0});
    vis[node] = true;
    vector<int> visn = {node};
    while(!q.empty()) {
        res += q.front().ff;
        int t = q.front().ff;
        int dis = q.front().ss;
        q.pop();
        if(dis == k) continue;
        for(const auto& val : v[t]) {
            if(!vis[val] && dis + 1 <= k) {
                vis[val] = true;
                q.push({val, dis + 1});
                visn.push_back(val);
            }
        }
    }
    for(int i = 0; i < sz(visn); ++i) vis[visn[i]] = false;
    return res;
}
// *-> KISS*
int solve() {
    int n, m; cin >> n >> m;
    v.assign(n + 1, vector<int>());
    vis.assign(n + 1, false);
    for(int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int q; cin >> q;
    while(q--) {
        int a, b; cin >> a >> b;
        cout << bfs(a, b) << '\n';
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

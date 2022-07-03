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

int n, k;
vector<vector<int>> v;
vector<bool> vis;
vector<int> dis, par;
void parent(int node, int p) {
    vis[node] = true;
    par[node] = p;
    for(const auto& val : v[node]) {
        if(!vis[val]) {
            parent(val, node);
        }
    }
}
int dfs(int node, int d) {
    vis[node] = true;
    if(dis[node] != -1 && dis[node] <= d) return 1;
    int child = 0, cnt = 0;
    for(const auto& val : v[node]) {
        if(!vis[val]) {
            ++child;
            int temp = dfs(val, d + 1);
            if(temp == -1) return -1;
            else cnt += temp;
        }
    }
    if(child == 0) {
        return -1;
    }
    return cnt;
}
int getAns() {
    vis[1] = true;
    int ans = 0;
    for(const auto& val : v[1]) {
        int res = dfs(val, 1);
        if(res == -1) return -1;
        ans += res;
    }
    return ans;
}
// *-> KISS*
int solve() {
    cin >> n >> k;
    deque<int> q;
    dis.assign(n + 1, -1);
    par = dis;
    v.assign(n + 1, vector<int>());
    vis.assign(n + 1, false);
    for (int i = 0; i < k; i++) {
        int t; cin >> t;
        q.push_back(t);
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    parent(1, -1);
    vis.assign(n + 1, false);
    for (int i = 0; i < sz(q); i++) {
        vis[q[i]] = true;
        dis[q[i]] = 0;
    }
    while(sz(q) != 0) {
        int f = q.front(); q.pop_front();
        int p = par[f];
        if(p == -1 || vis[p]) continue;
        else {
            vis[p] = true;
            dis[p] = dis[f] + 1;
            q.push_back(p);
        }
    }
    vis.assign(n + 1, false);
    int ans = getAns();
    cout << ans;
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool test = true;
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

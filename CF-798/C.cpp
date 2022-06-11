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

// *-> KISS*
vector<vector<int>> v;
vector<bool> vis;
vector<int> tot;
vector<int> dp;
int init(int node) {
    vis[node] = true;
    int sum = 1;
    for(const auto& val : v[node]) {
        if(!vis[val]) {
            sum += init(val);
        }
    }
    return tot[node] = sum;
}
int dfs(int node) {
    vis[node] = true;
    // Assume node is infected
    vector<int> temp;
    for(const auto& val : v[node]) if(!vis[val]) temp.push_back(val);
    if(sz(temp) == 0) dp[node] = 0;
    else if(sz(temp) == 1) {
        dp[node] = max(0, tot[temp[0]] - 1);
    }
    else {
        dp[node] = max({0, tot[temp[0]] - 1 + dfs(temp[1]), tot[temp[1]] - 1 + dfs(temp[0])});
    }
    return dp[node];
}
int solve() {
    int n; cin >> n;
    v.assign(n + 1, vector<int>());
    tot.assign(n + 1, 0);
    vis.assign(n + 1, false);
    dp.assign(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    init(1);
    vis.assign(n + 1, false);
    cout << dfs(1);
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

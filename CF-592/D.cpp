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

int n;
vector<array<ll, 3>> col;
vector<vector<int>> v;
vector<vector<vector<ll>>> dp;
vector<int> color;
bool bad(int node, int par) {
    if(sz(v[node]) >= 3) return true;
    for(const auto& val : v[node]) {
        if(val != par && bad(val, node)) return true;
    }
    return false;
}
void dfs(int node, int par) {
    vector<int> c;
    for(auto val : v[node]) if(val != par) c.push_back(val);
    for(auto val : c) dfs(val, node);
    if(sz(c) == 0) {
        // Leaf Node
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                if(i == j) continue;
                // i -> My color
                dp[node][i][j] = col[node][i];
            }
        }
    }
    else if(sz(c) == 1) {
        // Once Child
        for(int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; j++) {
                if(i == j) continue;
                dp[node][i][j] = col[node][i] + dp[c[0]][j][3 - i - j];
            }
        }
    }
}
void ret(int node, int ind, int ni, int par) {
    color[node] = ind;
    for(auto val : v[node]) {
        if(val != par) ret(val, ni, 3 - ni - ind, node);
    }
}
// *-> KISS*
int solve() {
    cin >> n;
    col.assign(n + 1, {0, 0, 0});
    v.assign(n + 1, vector<int>());
    color.assign(n + 1, 0);
    dp.assign(n + 1, vector<vector<ll>>(3, vector<ll>(3, 0)));
    // dp[i][j][k] -> Minimum cost of coloring the "i_th" node with "j" color, and my children are having
    // "k" color.
    for (int i = 0; i < n; i++) {
        cin >> col[i + 1][0];
    }
    for (int i = 0; i < n; i++) {
        cin >> col[i + 1][1];
    }
    for (int i = 0; i < n; i++) {
        cin >> col[i + 1][2];
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    // Assume to be Rooted at 1
    if(bad(1, -1)) {
        cout << -1;
        return 0;
    }
    dfs(1, -1);
    if(sz(v[1]) == 0) {
        int ind = -1;
        ll mini = LLONG_MAX;
        for(int i = 0; i < 3; ++i) {
            if(col[1][i] < mini) {
                mini = col[1][i];
                ind = i;
            }
        }
        cout << mini << '\n' << ind + 1;
        return 0;
    }
    if(sz(v[1]) == 1) {
        vector<int> t = {0, 1, 2};
        vector<int> ans;
        ll mini = LLONG_MAX;
        do {
            ll tt = (col[1][t[0]] + dp[v[1][0]][t[1]][t[2]]);
            if(tt < mini) mini = tt, ans = t;
        } while (next_permutation(all(t)));
        ret(1, ans[0], ans[1], -1);
        cout << mini << '\n';
    }
    else {
        vector<int> t = {0, 1, 2};
        vector<int> ans;
        ll mini = LLONG_MAX;
        do {
            ll tt = col[1][t[0]] + dp[v[1][0]][t[1]][t[2]] + dp[v[1][1]][t[2]][t[1]];
            if(tt < mini) mini = tt, ans = t;
        } while (next_permutation(all(t)));
        color[1] = ans[0];
        cout << mini << '\n';
        ret(v[1][0], ans[1], ans[2], 1);
        ret(v[1][1], ans[2], ans[1], 1);
    }
    for(int i = 1; i <= n; ++i) cout << color[i] + 1 << ' ';
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

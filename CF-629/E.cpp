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
vector<vector<int>> lca;
vector<int> level;
void dfs(int node, int lev, int par) {
    level[node] = lev;
    lca[node][0] = par;
    for(const auto& val : v[node]) {
        if(val != par) dfs(val, lev + 1, node);
    }
}
void LCA() {
    dfs(1, 0, -1);
    for(int i = 1; i < 32; ++i) {
        for(int j = 1; j <= sz(lca) - 1; ++j) {
            int par = lca[j][i - 1];
            if(par != -1) lca[j][i] = lca[par][i - 1];
        }
    }
}
// *-> KISS*
int solve() {
    int n, m; cin >> n >> m;
    v.assign(n + 1, vector<int>());
    lca.assign(n + 1, vector<int>(32, -1));
    level.assign(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    LCA();
    while(m--) {
        int k; cin >> k;
        vector<int> temp(k);
        for (int i = 0; i < k; i++) {
            cin >> temp[i];
        }
        sort(temp.begin(), temp.end(), [&](int a, int b) {
            return level[a] < level[b];
        });
        int node = temp[k - 1];
        bool f = true;
        while(sz(temp) && f) {
            if(level[temp.back()] == level[node]) {
                if(temp.back() == node) {
                    temp.pop_back();
                }
                else {
                    if(lca[node][0] == -1) {
                        f = false;
                    }
                    else if(lca[temp.back()][0] != lca[node][0]) f = false;
                    else {
                        temp.pop_back();
                    }
                }
            }
            else {
                int diff = level[node] - level[temp.back()];
                for(int j = 0; j < 32; ++j) {
                    if((diff >> j) & 1) {
                        node = lca[node][j];
                    }
                }
            }
        }
        if(f && sz(temp) == 0) cout << "YES\n";
        else cout << "NO\n";
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

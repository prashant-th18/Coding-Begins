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

// *-> KISS*
int solve() {
    int n; cin >> n;
    pair<int, int> a, b;
    vector<string> v(n);
    cin >> a.ff >> a.ss; --a.ff; --a.ss;
    cin >> b.ff >> b.ss; --b.ff; --b.ss;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int dx[] = {-1, -1, +1, +1};
    int dy[] = {-1, +1, +1, -1};
    queue<pair<int, int>> q;
    vector<vector<vector<bool>>> vis(n, vector<vector<bool>>(n, vector<bool>(4, false)));
    q.push(a);
    auto valid = [&](int i, int j, int dir) -> bool {
        if((i >= 0) && (i < n) && (j >= 0) && (j < n) && v[i][j] == '.' && !vis[i][j][dir]) return true;
        return false;
    };
    vector<vector<int>> dis(n, vector<int>(n, INT_MAX));
    dis[a.ff][a.ss] = 0;
    for(int j = 0; j < 4; ++j) vis[a.ff][a.ss][j] = true;
    while(!q.empty()) {
        auto p = q.front(); q.pop();
        if(p.ff == b.ff && p.ss == b.ss) break;
        for(int i = 0; i < 4; ++i) {
            for(int d = 1; ; ++d) {
                int ni = p.ff + d * dx[i],
                    nj = p.ss + d * dy[i];
                if(valid(ni, nj, i)) {
                    vis[ni][nj][i] = true;
                    bool f = false;
                    for(int j = 0; j < 4; ++j) {
                        if(i != j && vis[ni][nj][j]) f = true;
                    }
                    if(f) continue;
                    dis[ni][nj] = 1 + dis[p.ff][p.ss];
                    q.push(pair(ni, nj));
                }
                else break;
            }
        }
    }
    if(dis[b.ff][b.ss] == INT_MAX) dis[b.ff][b.ss] = -1;
    cout << dis[b.ff][b.ss];
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

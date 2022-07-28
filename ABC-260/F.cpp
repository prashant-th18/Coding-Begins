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

int s, t, m;
vector<vector<int>> v;
// *-> KISS*
int solve() {
    cin >> s >> t >> m;
    v.assign(s + t + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = s + 1; i <= s + t; ++i) {
        // Apply bfs
        queue<int> q;
        for(int j = 0; j < sz(v[i]); ++j) {
            q.push(v[i][j]);
        }
        unordered_map<int, vector<int>> mp;
        if(sz(q) == 1) continue;
        int t1 = -1, t2 = -1, t3 = -1;
        while(sz(q)) {
            bool f = false;
            int n = q.front(); q.pop();
            for(int j = 0; j < sz(v[n]); ++j) {
                if(v[n][j] == i) continue;
                mp[v[n][j]].push_back(n);
                if(sz(mp[v[n][j]]) == 2) {
                    t1 = mp[v[n][j]][0];
                    t2 = mp[v[n][j]][1];
                    t3 = v[n][j];
                    f = true;
                    break;
                }
            }
            if(f) break;
        }
        if(t1 != -1) {
            vector<int> temp = {t1, t2, t3, i};
            for(auto val : temp) cout << val << ' ';
            return 0;
        }
    }
    cout << -1;
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

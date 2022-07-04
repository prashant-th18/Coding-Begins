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

vector<vector<int>> to;
// *-> KISS*
int solve() {
    int n; cin >> n;
    to.assign(n, vector<int>());
    vector<int> v(n), dis(n, -1);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    auto p = [&](int num) -> bool {
        return num % 2 == 0;  
    };
    queue<int> q;
    vector<bool> vis(n, false);
    for(int i = 0; i < n; ++i) {
        int bi = i - v[i], ai = i + v[i];
        if(bi >= 0) {
            to[bi].push_back(i);
            if(p(v[bi]) ^ p(v[i])) {
                q.push(i);
                dis[i] = 1;
                vis[i] = true;
            }
        }
        if(ai < n) {
            to[ai].push_back(i);
            if(p(v[ai]) ^ p(v[i])) {
                if(!vis[i]) {
                    q.push(i);
                    dis[i] = 1;
                    vis[i] = true;
                }
            }
        }
    }
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(auto val : to[node]) {
            if(!vis[val]) {
                vis[val] = true;
                q.push(val);
                dis[val] = dis[node] + 1;
            }
        }
    }
    for(auto val : dis) cout << val << ' ';
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

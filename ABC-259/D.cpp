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
vector<vector<int>> v;
vector<bool> vis;
void dfs(int node) {
    vis[node] = true;
    for(const auto& val : v[node]) {
        if(!vis[val]) dfs(val);
    }
}
// *-> KISS*
int solve() {
    cin >> n;
    vis.assign(n + 1, false);
    v.assign(n + 1, vector<int>());
    vector<pair<ll, ll>> temp(n);
    vector<ll> r(n);
    pair<ll, ll> s, t;
    cin >> s.ff >> s.ss >> t.ff >> t.ss;
    for (int i = 0; i < n; i++) {
        cin >> temp[i].ff >> temp[i].ss;
        cin >> r[i];
    }
    int in1 = 0, in2 = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            ll x = temp[j].ff - temp[i].ff;
            ll y = temp[j].ss - temp[i].ss;
            ll d1 = x * x + y * y;
            ll d2 = r[i] * r[i] + r[j] * r[j] + 2 * r[i] * r[j];
            if(d1 <= d2 && (
                        !((temp[i].ff == temp[j].ff && temp[i].ss == temp[j].ss) && (r[i] != r[j]))
                        )) {
                v[i + 1].push_back(j + 1);
                v[j + 1].push_back(i + 1);
            }            
        }
        ll x = s.ff - temp[i].ff, y = s.ss - temp[i].ss;
        x *= x; y *= y;
        if(x + y == r[i] * r[i]) in1 = i + 1;
        x = t.ff - temp[i].ff, y = t.ss - temp[i].ss;
        x *= x; y *= y;
        if(x + y == r[i] * r[i]) in2 = i + 1;
    }
    dfs(in1);
    if(vis[in2]) cout << "Yes";
    else cout << "No";
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

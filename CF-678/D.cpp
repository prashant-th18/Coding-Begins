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
ll maxx = LLONG_MIN;
vector<vector<int>> v;
vector<ll> val;
pair<ll, ll> dfs(int node, int par) {
    ll tsum = val[node], tl = 0;
    int c = 0;
    for(const auto& vall : v[node]) {
        if(vall != par) {
            ++c;
            auto p = dfs(vall, node);
            tsum += p.first;
            tl += p.second;
        }
    }
    if(c == 0) {
        ++tl;
    }
    maxx = max(maxx, (tsum + tl - 1) / tl);
    return pair(tsum, tl);
}
// *-> KISS*
int solve() {
    cin >> n;
    v.assign(n + 1, vector<int>());
    val.assign(n + 1, 0LL);
    for (int i = 0; i < n - 1; i++) {
        int t; cin >> t;
        v[t].push_back(i + 2);
    }
    for (int i = 0; i < n; i++) {
        cin >> val[i + 1];
    }
    dfs(1, -1);
    cout << maxx;
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

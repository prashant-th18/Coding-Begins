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
#define MOD 1000000007
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
    int n, m; cin >> n >> m;
    vector<int> color(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> color[i + 1];
    }
    unordered_map<int, set<int>> mp;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        if(color[a] != color[b])
        {
            mp[color[a]].insert(color[b]);
            mp[color[b]].insert(color[a]);
        }
    }
    int ans = -1, ind = 1e9;
    for(auto &val : mp)
    {
        if(sz(val.ss) >= ans)
        {
            if(sz(val.ss) == ans) ind = min(ind, val.ff);
            else ind = val.ff;
            ans = sz(val.ss);
        }
    }
    if(ans == -1)
    {
        ind = *min_element(color.begin() + 1, color.end());
    }
    cout << ind;
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
}
// -> Keep It Simple Stupid!

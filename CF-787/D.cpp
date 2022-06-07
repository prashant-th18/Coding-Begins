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
int solve() {
    int n; cin >> n;
    vector<int> p(n + 1);
    vector<bool> pres(n + 1, false), vis(n + 1, false);
    for (int i = 0; i < n; i++) {
        cin >> p[i + 1];
        pres[p[i + 1]] = true;
    }
    if(n == 1) {
        cout << 1 << '\n' << 1 << '\n' << 1; return 0;
    }
    vector<int> leaf;
    for(int i = 0; i < n; ++i) {
        if(!pres[i + 1]) leaf.push_back(i + 1);
    }
    vector<vector<int>> ans;
    for(int i = 0; i < sz(leaf); ++i) {
        int node = leaf[i];
        vector<int> temp;
        do {
            vis[node] = true;
            temp.push_back(node);
            node = p[node];
        } while(!vis[node]);
        reverse(all(temp));
        ans.push_back(temp);
    }
    cout << sz(ans) << '\n';
    for(int i = 0; i < sz(ans); ++i) {
        cout << sz(ans[i]) << '\n';
        for(int j = 0; j < sz(ans[i]); ++j) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
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

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
    int n, m; cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    vector<vector<int>> mi(n, vector<int>(m, 0));
    auto ma = mi;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(i == 0 && j == 0) {
                mi[i][j] = ma[i][j] = v[i][j];
            }
            else if(i == 0) {
                mi[i][j] = v[i][j] + mi[i][j - 1];
                ma[i][j] = v[i][j] + ma[i][j - 1];
            }
            else if(j == 0) {
                mi[i][j] = v[i][j] + mi[i - 1][j];
                ma[i][j] = v[i][j] + ma[i - 1][j];
            }
            else {
                mi[i][j] = v[i][j] + min(mi[i - 1][j], mi[i][j - 1]);
                ma[i][j] = v[i][j] + max(ma[i - 1][j], ma[i][j - 1]);
            }
        }
    }
    if((n + m - 1) & 1) cout << "NO";
    else {
        if(mi[n - 1][m - 1] <= 0 && 0 <= ma[n - 1][m - 1]) cout << "YES";
        else cout << "NO";
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

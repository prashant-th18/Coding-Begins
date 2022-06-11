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
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    auto fun = [&](int num) -> int {
        if(num == -1) return -1;
        else return num + 1;
    };
    vector<vector<ll>> left(n + 2, vector<ll>(m + 2, -1));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            int upp = left[i][j + 1];
            int leff = left[i + 1][j];
            int maxi = ((v[i][j] == 'B') ? (0) : (INT_MIN));
            left[i + 1][j + 1] = max({maxi, fun(upp), fun(leff)});
        }
    }
    vector<vector<ll>> right(n + 2, vector<ll>(m + 2, -1));
    for(int i = 0; i < n; ++i) {
        for(int j = m - 1; j >= 0; --j) {
            int upp = right[i][j + 1];
            int rig = right[i + 1][j + 2];
            int maxi = ((v[i][j] == 'B') ? (0) : (INT_MIN));
            right[i + 1][j + 1] = max({maxi, fun(upp), fun(rig)});
        }
    }
    vector<vector<ll>> cdown(n + 2, vector<ll>(m + 2, -1));
    for(int j = 0; j < m; ++j) {
        for(int i = n - 1; i >= 0; --i) {
            int doww = cdown[i + 2][j + 1];
            int leff = cdown[i + 1][j];
            int maxi = ((v[i][j] == 'B') ? (0) : (INT_MIN));
            cdown[i + 1][j + 1] = max({maxi, fun(leff), fun(doww)});
        }
    }
    vector<vector<ll>> down(n + 2, vector<ll>(m + 2, -1));
    for(int j = m - 1; j >= 0; --j) {
        for(int i = n - 1; i >= 0; --i) {
            int rig = down[i + 1][j + 2];
            int doww = down[i + 2][j + 1];
            int maxi = ((v[i][j] == 'B') ? (0) : (INT_MIN));
            down[i + 1][j + 1] = max({maxi, fun(rig), fun(doww)});
        }
    }
    int maxx = INT_MAX, x, y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int lf = left[i + 1][j + 1];
            int rg = right[i + 1][j + 1];
            int cd = cdown[i + 1][j + 1];
            int dw = down[i + 1][j + 1];
            lf = max({lf, rg, cd, dw});
            if(lf != -1) {
                if(lf < maxx) {
                    maxx = lf;
                    x = i + 1, y = j + 1;
                }
            }
        }
    }
    cout << x << ' ' << y;
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

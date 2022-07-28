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
    int n, c; cin >> n >> c;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].ff >> v[i].ss;
    }
    vector<vector<int>> z(n, vector<int>(31, 0));
    auto o = z;
    auto apply = [&](int sym, int num, int pre) {
        if(sym == 1) {
            return num & pre;
        }
        else if(sym == 2) {
            return num | pre;
        }
        else return num ^ pre;
    };
    auto init = [&](vector<vector<int>>& f, int def) -> void {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < 31; ++j) {
                if(i == 0) {
                    f[i][j] = apply(v[i].ff, (v[i].ss >> j) & 1, def);
                }
                else {
                    f[i][j] = apply(v[i].ff, (v[i].ss >> j) & 1, f[i - 1][j]);
                }
            }
        }
    };
    init(z, 0);
    init(o, 1);
    for(int i = 0; i < n; ++i) {
        int num = 0;
        for(int j = 0; j < 31; ++j) {
            if((c >> j) & 1) {
                if(o[i][j] & 1) num += (1 << j);
            }
            else {
                if(z[i][j] & 1) num += (1 << j);
            }
        }
        cout << num << '\n';
        c = num;
    }
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

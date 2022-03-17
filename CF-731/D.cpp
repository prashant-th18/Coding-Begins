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
    vector<vector<int>> v(n, vector<int>(31, 0));
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        if(i == 0) ans = t;
        for (int j = 0; j < 31; j++) {
            v[i][j] = (t >> j) & 1;
        }
    }
    vector<int> res(n);
    res[0] = 0;
    for (int i = 1; i < n; i++) {
        int temp = 0;
        for (int j = 0; j < 31; j++) {
            int bit1 = v[i][j];
            int bit2 = (ans >> j) & 1;
            if(bit1 == 1 && bit2 == 0)
            {
                ans += (1 << j);
            }
            else if(bit1 == 0 && bit2 == 1)
            {
                temp += (1 << j);
            }
        }
        res[i] = temp;
    }
    for (int i = 0; i < n; i++) {
        cout << res[i] << ' ';
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

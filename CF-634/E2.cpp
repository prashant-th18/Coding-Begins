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
    int n; cin >> n;
    vector<int> v(n);
    vector<vector<int>> dp(n + 1, vector<int>(201, 0)), pos(201);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        pos[v[i]].push_back(i);
        for (int j = 0; j < 201; j++) {
            dp[i + 1][j] = dp[i][j] + (v[i] == j);
        }
    }
    int maxx = -1;
    for(int i = 1; i <= 200; ++i) {
        if(sz(pos[i]) == 0) continue;
        else {
            int s = 0, e = sz(pos[i]) - 1;
            while(s <= e) {
                if(s == e) {
                    maxx = max(maxx, s + 1 + (sz(pos[i]) - e - 1));
                }
                else {
                    int num = s + 1 + (sz(pos[i]) - e);
                    int maxi = 0;
                    for(int j = 1; j <= 200; ++j) {
                        maxi = max(maxi, dp[pos[i][e]][j] - dp[pos[i][s] + 1][j]);
                    }
                    maxx = max(maxx, num + maxi);
                }
                ++s, --e;
            }
        }
    }
    cout << maxx;
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool test = true;
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

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
    int n, maxx = INT_MIN; cin >> n;
    map<int, int> mp;
    vector<array<int, 3>> dp(n);
    vector<int> v(n);
    array<int, 3> ans;
    for(int i = 0; i < n; ++i) {
        int tt; cin >> tt;
        v[i] = tt;
        if(!mp.count(tt)) {
            dp[i] = {1, i, i};
        }
        else {
            dp[i] = {1, i, i};
            array<int, 3> temp = dp[mp[tt]];
            temp[0] += 1;
            temp[0] -= (i - temp[2] - 1);
            temp[2] = i;
            if(temp[0] > dp[i][0]) {
                dp[i] = temp;
            }
        }
        if(dp[i][0] > maxx) {
            maxx = dp[i][0];
            ans = dp[i];
        }
        mp[tt] = i;
    }
    cout << v[ans[2]] << ' ' << ans[1] + 1 << ' ' << ans[2] + 1;
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

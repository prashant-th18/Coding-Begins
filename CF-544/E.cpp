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
    int n, k; cin >> n >> k;
    vector<int> v(n);
    map<int, int> mp; // first occurrence
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        if(!mp.count(v[i])) mp[v[i]] = i;
    }
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for(int i = n - 1; i >= 0; --i) {
        for(int j = 0; j <= k; ++j) {
            if(j == 0) dp[i][j] = 0;
            else {
                auto it = mp.upper_bound(v[i] + 5);
                int cnt = 0;
                while(cnt < 5) {
                    ++cnt;
                    if(it == mp.end()) {
                        dp[i][j] = max(dp[i][j], (n - i));
                    }
                    else if((*it).ff > v[i]) {
                        dp[i][j] = max(dp[i][j], (*it).ss - i + dp[(*it).ss][j - 1]);
                    }
                    else break;
                    --it;
                }
                dp[i][j] = max(dp[i][j], dp[i + 1][j]);
            }
        }
    }
    cout << (*max_element(all(dp[0])));
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
    return 0;
}
// -> Keep It Simple Stupid!

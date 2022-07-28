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
    vector<vector<int>> v(n + 1);
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        v[t].push_back(i);
    }
    vector<int> ans(n + 1, 0);
    for(int i = 1; i <= n; ++i) {
        if(sz(v[i]) == 0) continue;
        vector<int>& pos = v[i];
        vector<array<int, 2>> dp(sz(pos), {0, 0});
        vector<int> odd, even;
        if(pos[sz(pos) - 1] % 2 == 0) {
            even.push_back(1);
        }
        else odd.push_back(1);
        int t = 1;
        for(int j = sz(pos) - 2; j >= 0; --j) {
            int elem = pos[j] % 2;
            if(elem == 0) {
                // Even
                if(sz(odd)) {
                    int maybe = 1 + odd.back();
                    t = max(t, maybe);
                    if(sz(even)) even.push_back(max(even.back(), maybe));
                    else even.push_back(maybe);
                }
                else {
                    if(sz(even) == 0) even.push_back(1);
                }
            }
            else {
                if(sz(even)) {
                    int maybe = 1 + even.back();
                    t = max(t, maybe);
                    if(sz(odd)) odd.push_back(max(odd.back(), maybe));
                    else odd.push_back(maybe);
                }
                else {
                    if(sz(odd) == 0) odd.push_back(1);
                }
            }
        }
        ans[i] = t;
    }
    for(int i = 1; i <= n; ++i) cout << ans[i] << ' ';
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

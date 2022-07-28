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

const int N = 6 * 1e6;
// *-> KISS*
int solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<vector<pair<int, int>>> dp(N);
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            int sum = v[i] + v[j];
            dp[sum].push_back(pair(i, j));
            if(sz(dp[sum]) == 1) continue;
            else {
                vector<int> ind;
                for(int k = 0; k < sz(dp[sum]); ++k) {
                    ind.push_back(dp[sum][k].ff);
                    ind.push_back(dp[sum][k].ss);
                }
                sort(all(ind));
                ind.resize(unique(all(ind)) - ind.begin());
                if(sz(ind) <= 3) continue;
                for(int k1 = 0; k1 < sz(ind); ++k1) {
                    for(int k2 = 0; k2 < sz(ind); ++k2) {
                        for(int k3 = 0; k3 < sz(ind); ++k3) {
                            for(int k4 = 0; k4 < sz(ind); ++k4) {
                                int t1 = ind[k1], t2 = ind[k2], t3 = ind[k3], t4 = ind[k4];
                                set<int> st = {t1, t2, t3, t4};
                                if(v[t1] + v[t2] == v[t3] + v[t4] && sz(st) == 4) {
                                    cout << "Yes\n";
                                    cout << t1 + 1 << ' ' << t2 + 1 << ' ' << t3 + 1 << ' ' << t4 + 1;
                                    return 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "No";
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

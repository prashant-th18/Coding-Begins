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
    string s; cin >> s;
    int n = sz(s);
    vector<int> dp(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        if(s[i] == '(') {
            st.push(i);
        }
        else {
            if(st.empty()) {
                dp[i] = 0;
            }
            else {
                int ind = st.top(); st.pop();
                dp[i] = (i - ind + 1);
                --ind;
                if(ind >= 0) dp[i] += dp[ind];
            }
        }
    }
    int maxx = -1, cur = 0;
    for (int i = 0; i < n; i++) {
        if(dp[i] > 0) {
            if(dp[i] > maxx) {
                maxx = dp[i]; cur = 1;
            }
            else if(dp[i] == maxx) cur++;
        }
    }
    if(maxx == -1) {
        cout << 0 << ' ' << 1;
    }
    else cout << maxx << ' ' << cur;
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

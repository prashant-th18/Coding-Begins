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
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        --v[i];
    }
    vector<int> order(n, -1), par(n, -1);
    set<pair<int, int>> st;
    for(int i = 0; i < n ; ++i) {
        if(k == 1) {
            order[v[i]] = i + 1;
        }
        else {
            auto it = st.lower_bound(pair(v[i], 0));
            if(it == st.end()) {
                par[v[i]] = -1;
                st.insert(pair(v[i], 1));
            }
            else {
                pair<int, int> temp = *it;
                st.erase(it);
                par[v[i]] = temp.ff;
                temp.ff = v[i];
                ++temp.ss;
                if(temp.ss == k) {
                    int t = v[i];
                    while(t != -1) {
                        order[t] = i + 1;
                        t = par[t];
                    }
                }
                else {
                    st.insert(temp);
                }
            }
        }
    }
    for(auto val : order) cout << val << '\n';
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

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
    vector<int> m(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> m[i];
    }
    vector<int> ms(k, 0);
    for (int i = 0; i < k; i++) {
        cin >> ms[i];
    }
    sort(m.begin(), m.end());
    multiset<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        st.insert(pair(ms[m[i] - 1], -m[i]));
    }
    vector<vector<int>> ans;
    while(sz(st)) {
        vector<int> t;
        int val = 1;
        auto it = st.lower_bound(pair(val, -k));
        while(it != st.end()) {
            t.push_back(-(*it).ss);
            ++val;
            st.erase(it);
            it = st.lower_bound(pair(val, -k));
        }
        ans.push_back(t);
    }
    cout << sz(ans) << '\n';
    for(auto& v1 : ans) {
        cout << sz(v1) << ' ';
        for(auto& v2: v1) cout << v2 << ' ';
        cout << '\n';
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

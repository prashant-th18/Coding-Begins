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
    int n, q; cin >> n >> q;
    string s; cin >> s;
    set<pair<int, int>> st;
    for (int i = 0; i < n - 1; i++) {
        if(i + 2 < n && s[i] == s[i + 2]) {
            st.insert(make_pair(i, i + 2));
        }
        if(s[i] == s[i + 1] && (i - 1) >= 0) st.insert(make_pair(i - 1, i + 1));
        if(s[i] == s[i + 1] && (i + 2) < n) st.insert(make_pair(i, i + 2));
    }
    while(q--) {
        int l, r; cin >> l >> r;
        --l, --r;
        auto it = st.lower_bound(make_pair(l, 0));
        if(it != st.end() && (*it).ss <= r) cout << "YES";
        else cout << "NO";
        cout << '\n';
    }
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

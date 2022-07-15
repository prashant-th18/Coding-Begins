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
    ll n, c, q; cin >> n >> c >> q;
    string s; cin >> s;
    set<array<ll, 3>> st;
    ll len = sz(s);
    vector<pair<ll, ll>> p(c);
    for(int i = 0; i < c; ++i) {
        cin >> p[i].ff >> p[i].ss;
    }
    for (int i = 0; i < c; i++) {
        ll l = p[i].ff, r = p[i].ss;
        array<ll, 3> temp = {len, l, r};
        len += (r - l + 1);
        st.insert(temp);
        if(len > (ll)1e18) break;
    }
    while(q--) {
        ll i; cin >> i;
        while(i > sz(s)) {
            auto it = st.lower_bound({i, 0LL, 0LL});
            --it;
            ll diff = (i - (*it)[0]);
            i = (*it)[1] + (diff - 1);
        }
        assert(i > 0);
        cout << s[i - 1] << '\n';
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

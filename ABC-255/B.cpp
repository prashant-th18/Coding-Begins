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
    ll n, k; cin >> n >> k;
    vector<bool> v(n, false);
    for (int i = 0; i < k; i++) {
        int t; cin >> t; --t;
        v[t] = true;
    }
    vector<pair<ll, ll>> l, nl;
    for(int i = 0; i < n; ++i) {
        int a, b; cin >> a >> b;
        if(v[i]) {
            l.push_back({a, b});
        }
        else nl.push_back({a, b});
    }
    ll maxi = LLONG_MIN;
    for(int i = 0; i < sz(nl); ++i) {
        ll ans = LLONG_MAX;
        for(int j = 0; j < sz(l); ++j) {
            ll x = nl[i].ff - l[j].ff, y = nl[i].ss - l[j].ss;
            ans = min(ans, x * x + y * y);
        }
        maxi = max(maxi, ans);
    }
    cout << sqrtl(maxi);
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    //cin >> TET;
    cout << fixed << setprecision(10);
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

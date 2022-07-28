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
    ll a, m; cin >> a >> m;
    ll g1 = gcd(a, m);
    vector<ll> v;
    vector<ll> keep;
    for(ll i = 1; i * i <= m; ++i) {
        if(m % i == 0) {
            v.push_back(i);
            if(i != m / i) v.push_back(m / i);
        }
    }
    keep.assign(sz(v), 0);
    ll ans = 0;
    sort(v.begin(), v.end());
    for(int i = sz(v) - 1; i >= 0; --i) {
        // 0 <= x < m 
        // a + x
        // [a, .. a + m - 1]
        ll myAns = (a + m - 1) / v[i] - (a - 1) / v[i];
        myAns -= keep[i];
        // effectively myAns generate krr rha hun
        for(int j = i - 1; j >= 0; --j) {
            if(v[i] % v[j] == 0) {
                keep[j] += myAns;
            }
        }
        if(v[i] == g1) {
            ans = myAns; break;
        }
    }
    cout << ans;
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

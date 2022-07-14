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
    ll n, k, x; cin >> n >> k >> x;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<>());
    for(int i = 0; i < n; ++i) {
        ll s = 0, e = k;
        ll ans = 0;
        while(s <= e) {
            ll mid = (s + e) >> 1;
            if(v[i] - mid * x >= 0) {
                ans = mid;
                s = mid + 1;
            }
            else e = mid - 1;
        }
        k -= ans;
        v[i] -= ans * x;
    }
    sort(v.begin(), v.end(), greater<>());
    for(int i = 0; i < n; ++i) {
        ll k_ = (v[i] + x - 1) / x;
        if(k_ <= k) {
            k -= k_;
            v[i] = 0;
        }
        else {
            v[i] -= k * x;
            k = 0;
        }
    }
    cout << accumulate(all(v), 0LL);
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

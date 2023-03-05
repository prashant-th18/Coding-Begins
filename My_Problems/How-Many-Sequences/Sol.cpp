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
const int MOD = 998244353;
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

ll add(ll a, ll b) {
    return (a + b) % MOD;
}
ll sub(ll a, ll b) {
    return (a - b + MOD) % MOD;
}
ll mul(ll a, ll b) {
    return a * b % MOD;
}
template<typename T>
T binexp(T a, T b) {
    T ans = 1;
    while (b) {
        if (b & 1) {
            ans = 1LL * ans * a % MOD;
        }
        a = 1LL * a * a % MOD;
        b >>= 1;
    }
    return ans;
}
// *-> KISS*
int solve() {
    int n; cin >> n;
    vector<int> occ(n + 2, 0);
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        occ[t]++;
    }
    ll sum = 0;
    for(int mex = 0; mex <= 1; ++mex) {
        ll ahead = 0, behind = 0;
        if(mex == 0) {
            // Calculate 1
            ahead = sub(binexp(2, occ[1]), 1);
            sum = add(sum, ahead);
        }
        else {
            behind = sub(binexp(2, occ[mex - 1]), 1);
            ahead = binexp(2, occ[mex + 1]);
            sum = add(sum, mul(behind, ahead));
        }
    }
    cout << sum;
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


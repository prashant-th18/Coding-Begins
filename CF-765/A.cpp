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
#define MOD 1000000007
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
    ll n, l; cin >> n >> l;
    vector<ll> v(n);
    for (ll &val : v) {
        cin >> val;
    }
    vector<ll> bit(32, 0);
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < 32; ++j)
        {
            bit[j] += ((v[i] & (1LL << j)) != 0);
        }
    }
    ll num = 0;
    for (int i = 0; i < 32; i++) {
        if(n & 1)
        {
            if(bit[i] > n / 2)
            {
                num += (1LL << i);
            }
        }
        else
        {
            if(bit[i] >= n / 2)
            {
                num += (1LL << i);
            }
        }
    }
    cout << num;
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    cin >> TET;
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
}
// -> Keep It Simple Stupid!

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

const int lim = 1000000;
// *-> KISS*
int solve() {
    vector<int> v = vector(4, INT_MAX);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            int t; cin >> t;
            v[j] = min(v[j], t);
        }
    }
    ll sum = accumulate(all(v), 0LL);
    if(sum < lim)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    else
    {
        for(int i = 3; i >= 0 && sum != lim; --i)
        {
            if(sum - v[i] > lim)
            {
                sum -= v[i];
                v[i] = 0;
            }
            else
            {
                // v[i] - k
                // sum - k == lim
                int k = sum - lim;
                v[i] -= k;
                sum = lim;
            }
        }
    }
    for(int i = 0; i < 4; ++i) cout << v[i] << ' ';
    assert(accumulate(all(v), 0LL) == lim);
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
        cout << "Case #" << i << ": ";
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

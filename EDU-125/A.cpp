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

vector<vector<ll>> v(51, vector<ll>(51, INT_MAX));
// *-> KISS*
int solve() {
    ll x, y; cin >> x >> y;
    cout << v[x][y];
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    cin >> TET;
    v[0][0] = 0;
    for(int i = 0; i <= 50; ++i)
    {
        for(int j = 0; j <= 50; ++j)
        {
            for(int k = i; k >= 0; --k)
            {
                for(int z = j; z >= 0; --z)
                {
                    ll dis = (i - k) * (i - k) + (z - j) * (z - j);
                    if((int)sqrt(dis) == ceil(sqrt(dis)))
                    {
                        v[i][j] = min(1 + v[k][z], v[i][j]);
                    }
                }
            }
        }
    }
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

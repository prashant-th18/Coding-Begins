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

constexpr ll inf = 1000000000000LL;
// *-> KISS*
int solve() {
    int n; cin >> n;
    vector<vector<ll>> v(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    vector<int> order(n);
    for (int i = 0; i < n; i++) {
        cin >> order[i];
    }
    reverse(all(order));
    vector<vector<ll>> d(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            d[i][j] = inf;
        }
    }
    vector<ll> a;
    vector<bool> exist(n, false);
    vector<int> till;
    for (int i = 0; i < n; i++) {
        exist[order[i] - 1] = true;
        till.push_back(order[i] - 1);
        for(int j = 0; j < n; ++j)
        {
            for(int k = 0; k < n; ++k)
            {
                if(exist[j] && exist[k])
                {
                    d[j][k] = min(d[j][k], v[j][k]);
                    d[k][j] = min(d[k][j], v[k][j]);
                }
            }
        }
        int temp = order[i] - 1;
        for (auto& k : till) {
            for (int ii = 0; ii < n; ii++) {
                d[ii][temp] = min(d[ii][temp], d[ii][k] + d[k][temp]);
                d[temp][ii] = min(d[temp][ii], d[temp][k] + d[k][ii]);
            }
        }
        for (int ii = 0; ii < n; ii++) {
            for (int jj = 0; jj < n; jj++) {
                d[ii][jj] = min(d[ii][jj], d[ii][temp] + d[temp][jj]);
            }
        }
        ll ans = 0;
        for (int ii = 0; ii < n; ii++) {
            for (int jj = 0; jj < n; jj++) {
                if(d[ii][jj] < inf) ans += d[ii][jj];
            }
        }
        a.push_back(ans);
    }
    reverse(all(a));
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    //cin >> TET;
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

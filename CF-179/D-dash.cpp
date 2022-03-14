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
    int n; cin >> n;
    vector<vector<ll>> d(n, vector<ll>(n, 1e12));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> d[i][j];
        }
    }
    vector<int> ord(n);
    for (int i = 0; i < n; i++) {
        cin >> ord[i];
        --ord[i];
    }
    reverse(all(ord));
    vector<ll> ans;
    for(int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                d[j][k] = min(d[j][k], d[j][ord[i]] + d[ord[i]][k]);
            }
        }
        ll a = 0;
        for(int ii = 0; ii <= i; ++ii)
        {
            for(int jj = 0; jj <= i; ++jj)
            {
                a += d[ord[ii]][ord[jj]];
            }
        }
        ans.push_back(a);
    }
    reverse(all(ans));
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
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

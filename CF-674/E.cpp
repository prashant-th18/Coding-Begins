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
    int n; cin >> n;
    vector<int> a(3), b(3);
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < 3; i++) {
        cin >> b[i];
    }
    int maxx = min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0]);
    int minn = INT_MAX;
    vector<pair<int, int>> order;
    order.push_back({0, 0}); order.push_back({0, 2});
    order.push_back({1, 1}); order.push_back({1, 0});
    order.push_back({2, 2}); order.push_back({2, 1});
    sort(order.begin(), order.end());
    do {
        auto ac = a, bc = b;
        for (int i = 0; i < sz(order); i++) {
            int mini = min(ac[order[i].ff], bc[order[i].ss]);
            ac[order[i].ff] -= mini;
            bc[order[i].ss] -= mini;
        }
        minn = min(minn, min(ac[0], bc[1]) + min(ac[1], bc[2]) + min(ac[2], bc[0]));
    } while (next_permutation(all(order)));
    cout << minn << ' ' << maxx;
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

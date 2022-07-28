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
    int n, q; cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<bool> vis(n, false);
    int maxx = -1, ans = 0;
    int s = 0, e = n;
    while(s <= e) {
        vector<bool> vi(n, false);
        int mid = (s + e) / 2;
        int temp = 0;
        for(int i = 0; i < mid; ++i) {
            if(v[i] <= q) {
                temp++;
                vi[i] = true;
            }
        }
        int tq = q;
        for(int i = mid; i < n; ++i) {
            if(v[i] <= tq) {
                ++temp;
                vi[i] = true;
            }
            else if(tq > 0) {
                --tq;
                ++temp;
                vi[i] = true;
            }
        }
        if(temp >= maxx) {
            vis = vi;
            maxx = temp;
        }
        if(tq == 0) {
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }
    for(int i = 0; i < n; ++i) {
        if(vis[i]) cout << '1';
        else cout << '0';
    }
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

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
    int index = 0, ans = 0, rq = q;
    vector<int> v(n);
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if(v[i] <= q) {
            vis[i] = true;
            index = i + 1;
            ++ans;
        }
    }
    for(int i = index; i < n; ++i) {
        if(q > 0) {
            vis[i] = true;
            --q;
            ++ans;
        }
    }
    q = rq;
    int s = 0, e = n;
    vector<bool> vi;
    while(s <= e) {
        vi.assign(n, false);
        int mid = (s + e) / 2;
        // [0 .. mid - 1] -> q
        // Fir interactive
        int temp = 0;
        for(int i = 0; i < mid; ++i) {
            temp += (v[i] <= q);
            if(v[i] <= q) vi[i] = true;
        }
        int tq = q;
        for(int i = mid; i < n; ++i) {
            if(v[i] <= tq) ++temp, vi[i] = true;
            else if(tq > 0) {
                ++temp;
                --tq;
                vi[i] = true;
            }
        }
        if(temp >= ans) {
            ans = temp;
            e = mid - 1;
            vis = vi;
        }
        else s = mid + 1;
    }
    for(int i = 0; i < n; ++i) {
        if(vis[i]) cout << "1";
        else cout << "0";
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

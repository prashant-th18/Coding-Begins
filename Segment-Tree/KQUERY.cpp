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

int n;
vector<int> v;
vector<vector<int>> t;
void build(int in = 1, int s = 0, int e = n - 1) {
    if(s == e) {
        t[in] = vector<int>(1, v[s]);
    }
    else {
        int mid = (s + e) / 2;
        build(2 * in, s, mid);
        build(2 * in + 1, mid + 1, e);
        merge(all(t[2 * in]), all(t[2 * in + 1]), back_inserter(t[in]));
    }
}
int query(int in, int s, int e, int qs, int qe, int x) {
    if(qs > qe) return 0;
    if(s == qs && e == qe) {
        auto ind = upper_bound(all(t[in]), x) - begin(t[in]);
        ind = sz(t[in]) - ind;
        return ind;
    }
    int mid = (s + e) / 2;
    return query(2 * in, s, mid, qs, min(qe, mid), x) + query(2 * in + 1, mid + 1, e, max(mid + 1, qs), qe, x);
}
// *-> KISS*
int solve() {
    cin >> n;
    v.assign(n, 0);
    t.assign(4 * n, vector<int>());
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    build();
    int q; cin >> q;
    while(q--) {
        int i, j, k; cin >> i >> j >> k;
        --i, --j;
        cout << query(1, 0, n - 1, i, j, k) << '\n';
    }
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

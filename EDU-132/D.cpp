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

int m;
vector<int> v, t;
void build(int in = 1, int s = 0, int e = m - 1) {
    if(s == e) {
        t[in] = v[s];
    }
    else {
        int mid = midpoint(s, e);
        build(2 * in, s, mid);
        build(2 * in + 1, mid + 1, e);
        t[in] = max(t[2 * in], t[2 * in + 1]);
    }
}
int query(int in, int s, int e, int qs, int qe) {
    if(qs > qe) return INT_MIN;
    if(s == qs && e == qe) return t[in];
    int mid = midpoint(s, e);
    return max(query(2 * in, s, mid, qs, min(qe, mid)), query(2 * in + 1, mid + 1, e, max(mid + 1, qs), qe));
}
// *-> KISS*
int solve() {
    int n; cin >> n >> m;
    v.assign(m, 0);
    t.assign(4 * m, 0);
    for (int i = 0; i < m; i++) {
        cin >> v[i];
    }
    build();
    int q; cin >> q;
    while(q--) {
        int xa, xb, ya, yb;
        cin >> xa >> ya >> xb >> yb;
        // x height btara
        --ya;
        --yb;
        int k; cin >> k;
        // n maximum
        ll z = ((ll)(n - xa) + k - 1) / k;
        if(xa + z * k > n) --z;
        ll h = xa + z * k; // <= n
        if(ya == yb) {
            if(abs(xa - xb) % k == 0) cout << "Yes\n";
            else cout << "No\n";
        }
        else {
            int maxx = query(1, 0, m - 1, min(ya, yb), max(ya, yb));
            if(h <= maxx || abs(yb - ya) % k != 0 || (h - xb) % k != 0) {
                cout << "No\n";
            }
            else {
                cout << "Yes\n";
            }
        }
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

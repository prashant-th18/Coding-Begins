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
using pii = pair<int, int>;

// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// #define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered Set */
// #define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered MultiSet */

int n;
vector<int> v;
vector<int> t1;
vector<pii> t2;
pii combine(const pii& a, const pii& b) {
    if(a.ff < b.ff) return a;
    if(b.ff < a.ff) return b;
    return pii(a.ff, a.ss + b.ss);
}
void build1(int in = 1, int s = 0, int e = n - 1) {
    if(s == e) t1[in] = v[s];
    else {
        int mid = (s + e) / 2;
        build1(2 * in, s, mid);
        build1(2 * in + 1, mid + 1, e);
        t1[in] = __gcd(t1[2 * in], t1[2 * in + 1]);
    }
}
void build2(int in = 1, int s = 0, int e = n - 1) {
    if(s == e) t2[in] = pii(v[s], 1);
    else {
        int mid = (s + e) / 2;
        build2(2 * in, s, mid);
        build2(2 * in + 1, mid + 1, e);
        t2[in] = combine(t2[2 * in], t2[2 * in + 1]);
    }
}
int q1(int in, int s, int e, int qs, int qe) {
    if(qs > qe) return 0;
    if(s == qs && e == qe) return t1[in];
    int mid = (s + e) / 2;
    return __gcd(q1(2 * in, s, mid, qs, min(mid, qe)), q1(2 * in + 1, mid + 1, e, max(qs, mid + 1), qe));
}
pii q2(int in, int s, int e, int qs, int qe) {
    if(qs > qe) return pii(INT_MAX, 0);
    if(s == qs && e == qe) return t2[in];
    int mid = (s + e) / 2;
    return combine(q2(2 * in, s, mid, qs, min(qe, mid)), q2(2 * in + 1, mid + 1, e, max(mid + 1, qs), qe));
}
// *-> KISS*
int solve() {
    cin >> n;
    v.assign(n, 0);
    t1.assign(4 * n, 0);
    t2.assign(4 * n, pii(0, 0));
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    build1();
    build2();
    int q; cin >> q;
    while(q--) {
        int l, r; cin >> l >> r;
        --l, --r;
        int gg = q1(1, 0, n - 1, l, r);
        pii temp = q2(1, 0, n - 1, l, r);
        int ans = r - l + 1;
        if(temp.ff == gg) ans -= temp.ss;
        cout << ans << '\n';
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

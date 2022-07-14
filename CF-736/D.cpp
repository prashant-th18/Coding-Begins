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
vector<ll> t, a;
void build(int in = 1, int s = 0, int e = n - 1) {
    if(s == e) {
        t[in] = a[s];
    }
    else {
        int mid = midpoint(s, e);
        build(2 * in, s, mid);
        build(2 * in + 1, mid + 1, e);
        t[in] = __gcd(t[2 * in], t[2 * in + 1]);
    }
}
ll query(int in, int s, int e, int qs, int qe) {
    if(qs > qe) return 0; // Doesn't affect GCD
    if(s == qs && e == qe) return t[in];
    int mid = (s + e) / 2;
    return __gcd(query(2 * in, s, mid, qs, min(mid, qe)), query(2 * in + 1, mid + 1, e, max(mid + 1, qs), qe));
}
// *-> KISS*
int solve() {
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    if(n == 1) {
        cout << 1; return 0;
    }
    --n; /// n is decreased
    t.assign(4 * n, 0);
    a.assign(n, 0);
    for(int i = 0; i < n; ++i) {
        a[i] = abs(v[i] - v[i + 1]);
    }
    build();
    int ans = 1;
    for(int i = 0; i < n; ++i) {
        int s = i, e = n - 1;
        int temp = 1;
        while(s <= e) {
            int mid = midpoint(s, e);
            ll get = query(1, 0, n - 1, i, mid);
            if(get >= 2) {
                temp = (mid - i + 2);
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }
        ans = max(ans, temp);
    }
    cout << ans;
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

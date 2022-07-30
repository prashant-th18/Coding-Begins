#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif
#include "bits/stdc++.h"
using namespace std;
const int MOD = 1000000007;
typedef long long ll;
typedef long double ld;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)
#define ff first
#define ss second

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int n, q;
vector<ll> v, t;
void build(int in = 1, int s = 0, int e = n - 1) {
    if(s == e) t[in] = v[s];
    else {
        int mid = (s + e) >> 1;
        build(2 * in, s, mid);
        build(2 * in + 1, mid + 1, e);
        t[in] = min(t[2 * in], t[2 * in + 1]);
    }
}
void update(int in, int s, int e, int pos, int nval) {
    if(s == e) {
        t[in] = nval;
    }
    else {
        int mid = (s + e) >> 1;
        if(pos <= mid) {
            update(2 * in, s, mid, pos, nval);
        }
        else update(2 * in + 1, mid + 1, e, pos, nval);
        t[in] = min(t[2 * in], t[2 * in + 1]);
    }
}
ll get(int in, int s, int e, int qs, int qe) {
    if(qs > qe) return INT_MAX;
    if(s == qs && e == qe) return t[in];
    int mid = (s + e) >> 1;
    return min(get(2 * in, s, mid, qs, min(qe, mid)), get(2 * in + 1, mid + 1, e, max(qs, mid + 1), qe));
}
// *-> KISS*
int solve() {
    cin >> n >> q;
    v.assign(n, 0);
    t.assign(4 * n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    build();
    while(q--) {
        int ty; cin >> ty;
        if(ty == 1) {
            int i, j; cin >> i >> j;
            --i;
            update(1, 0, n - 1, i, j);
        }
        else {
            int i, j; cin >> i >> j;
            --i; --j;
            cout << get(1, 0, n - 1, i, j) << '\n';
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

        if (solve()) {
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


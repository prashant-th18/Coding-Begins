#ifdef LOCAL
    #define _GLIBCXX_DEBUG
    #include "debug.h"
#else
    #include "bits/stdc++.h"
    using namespace std;
    typedef long long ll;
    #define sz(s) ((int)s.size())
    #define all(v) begin(v), end(v)
    #define debug(...)
#endif

typedef long double ld;
const int MOD = 1000000007;
#define ff first
#define ss second
using pll = pair<ll, ll>;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int n, k;
vector<ll> v, pre;
vector<pll> t;
pll combine(pll a, pll b) {
    if(a.ff != b.ff)
    return max(a, b);

    return min(a, b);
}
void build(int in = 1, int s = 0, int e = n - 1) {
    if(s == e) {
        t[in] = pll(pre[s], s);
    }
    else {
        int mid = (s + e) >> 1;
        build(2 * in, s, mid);
        build(2 * in + 1, mid + 1, e);
        t[in] = combine(t[2 * in], t[2 * in + 1]);
    }
}
pll query(int in, int s, int e, int qs, int qe) {
    if(qs > qe) return {LLONG_MIN, -1};
    if(s == qs && e == qe) return t[in];
    int mid = (s + e) >> 1;
    return combine(query(2 * in, s, mid, qs, min(qe, mid)),
            query(2 * in + 1, mid + 1, e, max(qs, mid + 1), qe));
}
// *-> KISS*
int solve() {
    cin >> n >> k;
    v.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    reverse(all(v));
    pre.assign(n, 0);
    pre[0] = v[0];
    for(int i = 1; i < n; ++i) {
        pre[i] = pre[i - 1] + v[i];
    }
    t.assign(4 * n, pll(0, 0));
    build();
    ll sum = 0;
    int index = 0;
    for(ll i = k; i >= 2; --i) {
        pll tt = query(1, 0, n - 1, index, n - i);
        debug(tt);
        sum += i * (tt.ff - ((index == 0 ? 0 : pre[index - 1])));
        index = tt.ss + 1;
    }
    sum += pre[n - 1] - (index == 0 ? 0 : pre[index - 1]);
    cout << sum;
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

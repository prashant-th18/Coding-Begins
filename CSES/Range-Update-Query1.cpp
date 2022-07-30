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
vector<ll> v, bit;
void update(int in, ll delta) {
    for(; in <= n; in += (in & -in)) {
        bit[in] += delta;
    }
}
ll sum(int in) {
    ll res = 0;
    for(; in > 0; in -= (in & -in)) {
        res += bit[in];
    }
    return res;
}
// *-> KISS*
int solve() {
    cin >> n >> q;
    v.assign(n + 1, 0LL);
    bit.assign(n + 1, 0LL);
    for(int i = 1; i <= n; ++i) cin >> v[i];
    // v[i] = diff[0] + diff[1] + diff[2] ... + diff[i]
    // diff[i] = arr[i] - arr[i - 1]
    for(int i = 1; i <= n; ++i) update(i, v[i] - v[i - 1]);
    while(q--) {
        int t; cin >> t;
        if(t == 1) {
            ll a, b, u; cin >> a >> b >> u;
            update(a, u);
            update(b + 1, -u);
        }
        else {
            int i; cin >> i;
            cout << sum(i) << '\n';
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

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
using pll = pair<ll, ll>;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// *-> KISS*
int solve() {
    int n; cin >> n;
    vector<int> v(n), h(n);
    vector<pll> p;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        p.push_back(pair(v[i], i));
    }
    sort(p.begin(), p.end(), [&](pll a, pll b) {
        if(a.ff != b.ff) return a.ff < b.ff;
        return a.ss > b.ss;
    });
    for (int i = 0; i < n; i++) {
        h[p[i].ss] = i + 1;
    }
    auto add = [&](ll a, ll b) {
        return (a + b) % MOD;
    };
    auto sub = [&](ll a, ll b) {
        return (a - b + MOD) % MOD;
    };
    vector<ll> bit(n + 1, 0);
    auto update = [&](int in, ll delta) {
        for(; in <= n; in += in & -in) {
            bit[in] = add(bit[in], delta);
        }
    };
    auto sum = [&](int in) {
        ll s = 0;
        for(; in > 0; in -= in & -in) {
            s = add(s, bit[in]);
        }
        return s;
    };
    ll ans = 0;
    for(int i = n - 1; i >= 0; --i) {
        ll my = 1;
        my = add(my, sub(sum(n), sum(h[i])));
        ans = add(ans, my);
        update(h[i], my);
    }
    cout << ans;
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

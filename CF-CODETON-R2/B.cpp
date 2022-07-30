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
    ll x; cin >> x;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<pll> range(n);
    for (int i = 0; i < n; i++) {
        range[i].ff = -x + v[i];
        range[i].ss = x + v[i];
    }
    ll xx = range[0].ff, yy = range[0].ss;
    ll ans = 0;
    for(int i = 1; i < n; ++i) {
        // Check overlap
        ll maxx = max(range[i].ff, xx);
        ll minn = min(range[i].ss, yy);
        if(maxx > minn) {
            ++ans;
            xx = range[i].ff, yy = range[i].ss;
        }
        else {
            xx = maxx; yy = minn;
        }
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

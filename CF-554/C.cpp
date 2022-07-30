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

// *-> KISS*
void check() {
    for(ll i = 1; i <= 100; ++i) {
        for(ll j = i; j <= i + 100; ++j) {
            ll lc = lcm(i, j);
            ll ans = 0;
            for(int k = 1; k <= 1000; ++k) {
                if(lcm(i + k, j + k) < lc) {
                    lc = lcm(i + k, j + k);
                    ans = k;
                }
            }
            cout << i << " -- " << j << "  --->  " << ans << endl;
        }
    }
}
int solve() {
    ll a, b; cin >> a >> b;
    if(a > b) swap(a, b);
    // Function
    auto check = [&](ll x, ll y) -> bool {
        ll g = gcd(x, y);
        x /= g;
        if(x > (ll)1e18 / y) return false;
        return true;
    };
    //
    ll dif = b - a, maxx = lcm(a, b), ans = 0;
    // Function
    auto getAns = [&](ll div) -> void {
        ll t = (a + div - 1) / div * div - a;
        ll na = a + t, nb = b + t;
        if(check(na, nb)) {
            ll lc = lcm(na, nb);
            if(lc <= maxx) {
                if(lc < maxx) {
                    ans = t;
                }
                else ans = min(ans, t);
                maxx = lc;
            }
        }
    };
    //
    for(ll i = 1; i * i <= dif; ++i) {
        if(dif % i == 0) {
            ll n1 = i, n2 = dif / i;
            if(n1 != 1) {
                getAns(n1);
            }
            getAns(n2);
        }
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

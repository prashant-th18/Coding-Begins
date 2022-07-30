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
int solve() {
    auto over = [&](ll a, ll b, ll x, ll y) {
        if(max(a, b) < min(x, y) || max(x, y) < min(a, b)) return true;
        return false;
    };
    ll x, y; cin >> x >> y;
    for(ll i = 1; i * i <= y; ++i) {
        if(y % i == 0) {
            ll n1 = i, n2 = y / i;
            ll s1 = n2 + 1, s2 = x - s1;
            ll d = (s2 < 0) ? (-s2) : (0);
            s2 += d;
            s1 -= d;

            if(min(s1, s2) >= 0 && over(n1, n2, s1, s2)) {
                cout << n1 << ' ' << n2 << '\n' << min(s1, s2) << ' ' << max(s1, s2) << '\n'; return 0;
            }
            s1 = n1 - 1;
            s2 = x - s1;
            d = (s2 < 0) ? (-s2) : (0);
            s2 += d;
            s1 -= d;
            if(min(s1, s2) >= 0 && over(n1, n2, s1, s2)) {
                cout << n1 << ' ' << n2 << '\n' << min(s1, s2) << ' ' << max(s1, s2); return 0;
            }
        }
    }
    cout << -1;
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

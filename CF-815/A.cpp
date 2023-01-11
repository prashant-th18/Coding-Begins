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

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// *-> KISS*
int solve() {
    ll a, b, c, d; cin >> a >> b >> c >> d;
    if(a == 0 || c == 0) {
        if(a == 0 && c == 0) cout << 0;
        else {
            cout << 1;
        }
        return 0;
    }
    ll g1 = gcd(a, b), g2 = gcd(c, d);
    a /= g1, b /= g1, c /= g2, d /= g2;
    debug(a, b, c, d);
    if(a * d == b * c) cout << 0;
    else {
        ll maxx = max(a * d, b * c), minn = min(a * d, b * c);
        if(maxx % minn == 0) cout << 1;
        else cout << 2;
    }
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

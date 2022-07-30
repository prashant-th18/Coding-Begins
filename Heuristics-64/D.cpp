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
    ll n, x, y, e, l; cin >> n >> x >> y >> e >> l;
    ll cap = 0, xx = 0, yy = 0;
    for (int i = 0; i < n; i++) {
        ll a, b, c; cin >> a >> b >> c;
        e -= cap * (abs(xx - a) + abs(yy - b));
        if(e < 0) {
            cout << 0; return 0;
        }
        else {
            cap += c;
            if(cap >= l) {
                cout << 1; return 0;
            }
        }
        xx = a; yy = b;
    }
    cout << 0;
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

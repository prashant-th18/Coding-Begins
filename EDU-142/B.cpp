#ifdef LOCAL
	#define _GLIBCXX_DEBUG
#endif
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)

typedef long double ld;
const int MOD = 1000000007;
#define ff first
#define ss second

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// *-> KISS*
int solve() {
    // int n; cin >> n;
    ll a, b, c, d; cin >> a >> b >> c >> d;
    ll alice = a, bob = a;
    if(a == 0) {
    	cout << (b > 0 || c > 0 || d > 0);
    }
    else {
    	if(abs(b - c) <= a) {
    		ll ans = a + b + c;
    		ll ex = b - c;
    		alice += ex;
    		bob -= ex;
    		ex = min(alice, min(bob, d));
    		d -= ex;
    		ans += ex;
    		ans += (d > 0);
    		cout << ans;
    	}
    	else {
    		ll ans = a;
    		ll num = (b + c - abs(abs(b - c) - a));
            assert(num != b + c);
            ans += num;
            ++ans;
    		cout << ans;
    	}
    }
	return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int TET = 1;
    cin >> TET;
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
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
    vector<ll> b(3), c(3);
	cin >> b[0] >> b[1] >> b[2] >> c[0] >> c[1] >> c[2];
	// c[0], c[1], c[2] -> First Term, Common Difference, Number of Terms
	ll dif = c[1];
	ll ans = 0;
	auto add = [&](ll x, ll y) {
		return (x + y) % MOD;
	};
	auto gcdCheck = [&](ll x) {
		return gcd(x, b[1]) == 1;
	};
	for(ll i = 1; i * i <= dif; ++i) {
		if(dif % i == 0) {
			if(i != 1 && gcdCheck(i)) {
				
			}
		}
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

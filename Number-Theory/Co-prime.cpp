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
    ll l, r; cin >> l >> r;
	ll n; cin >> n;
	vector<ll> prime;
	for(ll i = 2; i * i <= n; ++i) {
		if(n % i == 0) {
			prime.push_back(i);
			while(n % i == 0) n /= i;
		}
	}
	if(n > 1) prime.push_back(n);
	// Prime Factorized
	ll ans = 0;
	for(ll i = 1; i < (1 << sz(prime)); ++i) {
		ll t = 1;
		for(int j = 0; j < sz(prime); ++j) {
			if(i & (1 << j)) {
				t *= prime[j];
			}
		}
		ll how = 0;
		int cnt = __builtin_popcount(i);
		how = (r / t) - (l - 1) / t;
		if(cnt & 1) ans += how;
		else ans -= how;
	}
	ans = r - l + 1 - ans;
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
		cout << "Case #" << i << ": ";
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

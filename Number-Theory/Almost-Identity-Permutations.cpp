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
const ll MOD = LLONG_MAX;
#define ff first
#define ss second

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

ll nCr(ll n, ll r) {
	if(r == 1) return n;
	else if(r == 2) {
		return n * (n - 1) / 2;
	}
	else if(r == 3) {
		return n * (n - 1) * (n - 2) / 6;
	}
	else {
		return n * (n - 1) * (n - 2) * (n - 3) / 24;
	}
}
// *-> KISS*
int solve() {
	ll n, k; cin >> n >> k;
	vector<ll> dp(11, 0);
	dp[2] = 1;
	for(ll i = 3; i < 10; ++i) {
		dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
	}
	ll ans = 1;
	for(int i = k; i >= 2; --i) {
		ll t = i;
		ll a = nCr(n, t);
		ans = (ans + a * dp[i]);
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

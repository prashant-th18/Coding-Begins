#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)

typedef long double ld;
const ll MOD = 998244353;
#define ff first
#define ss second

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int N = 501;
vector<ll> fact(N, 1);
vector<vector<ll>> dp(N, vector<ll>(N, 0));
template<typename T>
T binexp(T a, T b) {
	T ans = 1;
	while (b) {
		if (b & 1) {
			ans = 1LL * ans * a % MOD;
		}
		a = 1LL * a * a % MOD;
		b >>= 1;
	}
	return ans;
}
ll modinv(ll x) {
	return binexp(x, MOD - 2);
}
void init() {
	for(ll i = 2; i < N; ++i) {
		fact[i] = i * fact[i - 1] % MOD;
	}
	for(ll i = 1; i < N; ++i) {
		for(ll j = 1; j <= i; ++j) {
			// dp[i][j] = i! / (j! * (i - j)!)
			dp[i][j] = (fact[i] * modinv(fact[j]) % MOD * modinv(fact[i - j]) % MOD);
		}
	}
}
// *-> KISS*
int solve() {
	ll n, x; cin >> n >> x;
	ll ans = 1LL;
	auto add = [&](ll a, ll b) {
		return (a + b) % MOD;
	};
	for(ll i = 2; i <= x; ++i) {
		if(i < n) {
			// C1
			ll t = n * binexp(i - 1, n - 1) % MOD;
			ans = add(ans, t);
		}
		else if(i > n) {
			// C1
			ll rem = i % (n - 1);
			if(rem == 0) rem = n - 1;
			if(rem != 1) {
				// Now, I have to take use of "rem" elements
				ll elem = rem - 1;
				ll t = n * dp[n - 1][rem] % MOD * 
					binexp(elem, rem) % MOD * binexp(i - 1, n - 1 - rem) % MOD;
				ans = add(ans, t);
			}
		}
		// C2, C3, C4, ... CN
		for(ll j = 2; j <= n; ++j) {
			ll t = dp[n][j] * binexp(i - 1, n - j) % MOD;
			ans = add(ans, t);
		}
	}
	cout << ans;
	return 0;
}
int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	bool test = false;
	init();
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

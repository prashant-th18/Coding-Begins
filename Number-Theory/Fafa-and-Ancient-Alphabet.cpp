#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)
#define debug(...)

typedef long double ld;
const ll MOD = 1000000007;
#define ff first
#define ss second

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
ll mul(ll a, ll b) {
	return a * b % MOD;
}
ll add(ll a, ll b) {
	return (a + b) % MOD;
}
ll sub(ll a, ll b) {
	return (a - b + MOD) % MOD;
}
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// *-> KISS*
int solve() {
	ll n, m; cin >> n >> m;
	vector<ll> a(n), b(n);
	for(int i = 0; i < n; ++i) cin >> a[i];
	for(int i = 0; i < n; ++i) cin >> b[i];
	vector<ll> dp(n + 1, 0);
	for(int i = n - 1; i >= 0; --i) {
		dp[i] = dp[i + 1] + (a[i] == 0) + (b[i] == 0);
	}
	// i
	// 0 => 1, 2, 3, ... , i - 1. Total = (i - 1) numbers.
	// => "jth" ->> dp[j + 1] -> zeros
	// modinv(m) * (modinv(m) ^ dp[j + 1])  + .. [i - 1] times
	// (i - 1) * ((m * modinv(m)) ^ (dp[j + 1] + 1))
	ll mod = modinv(m);
	ll azero = mul(mul(m, m - 1), modinv(2)), modpow = binexp(mod, 2LL);
	ll ans = 0, pre = 1LL;
	for(int i = 0; i < n; ++i) {
		if(a[i] == 0 && b[i] == 0) {
			ll p = azero;
			p = mul(p, modpow);
			p = mul(p, pre);
			p = mul(p, binexp(mul(m, mod), dp[i + 1]));
			ans = add(ans, p);
			// m * modinv(m)
			pre = mul(pre, mul(m, modpow));
		}
		else if(a[i] * b[i] == 0) {
			ll num = 0;
			if(a[i] == 0) {
				num = m - b[i];
			}
			else {
				num = a[i] - 1;
			}
			ll p = binexp(mul(m, mod), dp[i + 1]);
			p = mul(p, mul(num, mod));
			ans = add(ans, mul(p, pre));
			pre = mul(pre, mod);
		}
		else {
			if(a[i] < b[i]) {
				pre = 0; break;
			}
			else if(a[i] > b[i]) {
				ans = add(ans, mul(pre, binexp(mul(m, mod), dp[i + 1])));
				break;
			}
			else continue;
		}
		if(i == n - 1) pre = 0;
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

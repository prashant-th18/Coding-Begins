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
const ll MOD = 998244353;
#define ff first
#define ss second
using pll = pair<ll, ll>;
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
	if(x == 0) return 1;
	return binexp(x, MOD - 2);
}
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// *-> KISS*
int solve() {
	vector<ll> fact(301, 1);
	for(ll i = 1; i < 301; ++i) {
		fact[i] = i * fact[i - 1] % MOD;
	}
	ll n, m; cin >> n >> m;
	// c1 * A + c2 * C + c3 * E == Xi
	// Similiar for Yi
	ll a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;
	set<pair<ll, ll>> mp;
	for (int i = 0; i < m; i++) {
		ll x, y; cin >> x >> y;
		mp.insert(pll(x, y));
	}
	ll ans = 0;
	for(ll c1 = 0; c1 <= n; ++c1) {
		for(ll c2 = 0; c2 <= n; ++c2) {
			for(ll c3 = 0; c3 <= n; ++c3) {
				if(c1 + c2 + c3 == 0) continue;
				if(c1 + c2 + c3 > n) continue;
				ll x = c1 * a + c2 * c + c3 * e;
				ll y = c1 * b + c2 * d + c3 * f;
				ll tt = fact[c1 + c2 + c3] * modinv(c1) % MOD * modinv(c2) % MOD * modinv(c3) % MOD;
				if(mp.count(pll(x, y))) {
					ll left = n - c1 - c2 - c3;
					ll t1 = binexp(3LL, left);
					t1 = t1 * tt % MOD;
					debug(t1);
					ans = (ans - t1 + MOD) % MOD;
				}
				else if(c1 + c2 + c3 == n) {
					debug(x, y, tt);
					ans = (ans + tt) % MOD;
				}
			}
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
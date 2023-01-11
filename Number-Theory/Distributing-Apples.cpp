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
const ll MOD = 1000000007;
#define ff first
#define ss second

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

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
// *-> KISS*
int solve() {
    ll n, m; cin >> n >> m;
	// Suppose p is person
	// p0 + p1 + p2 + ... = m
	// where pi >= 0;
	// n + r - 1 C r - 1;
	// OR C(n + m - 1, m - 1)
	vector<ll> fact(2e6 + 1, 1);
	for(ll i = 2; i < 2e6 + 1; ++i) fact[i] = i * fact[i - 1] % MOD;
	ll up = fact[n + m - 1];
	ll d1 = modinv(fact[m]), d2 = modinv(fact[n - 1]);
	cout << up * d1 % MOD * d2 % MOD;
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

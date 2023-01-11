#ifdef LOCAL
	#define _GLIBCXX_DEBUG
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
T binexp(T a, T b, ll mod = MOD) {
	T ans = 1;
	while (b) {
		if (b & 1) {
			ans = 1LL * ans * a % mod;
		}
		a = 1LL * a * a % mod;
		b >>= 1;
	}
	return ans;
}
ll modinv(ll x) {
	return binexp(x, MOD - 2);
}
// *-> KISS*
int solve() {
    ll a, b, c; cin >> a >> b >> c;
	// a ^ (b ^ c)
	// pi[MOD] = MOD - 1;
	// a ^ (b ^ c % (MOD - 1)) % MOD;
	ll res = binexp(b, c, MOD - 1);
	res = binexp(a, res);
	cout << res;
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

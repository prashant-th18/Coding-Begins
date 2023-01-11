#ifdef LOCAL
	#define _GLIBCXX_DEBUG
#endif
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)

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
const int N = 3e6;
// *-> KISS*
int solve() {
    int n; cin >> n;
	++n;
	vector<ll> fact(N, 1);
	for(ll i = 2; i < N; ++i) {
		fact[i] = i * fact[i - 1] % MOD;
	}
	ll t = fact[2 * n] * modinv(fact[n]) % MOD * modinv(fact[n]) % MOD;
	t = (t - 1 + MOD) % MOD;
	cout << t;
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

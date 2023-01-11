#ifdef LOCAL
	#define _GLIBCXX_DEBUG
#endif
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)

typedef long double ld;
const int MOD = 998244353;
#define ff first
#define ss second

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

ll binexp(ll a, ll b) {
	ll res = 1;
	while(b) {
		if(b & 1) {
			res = res * a % MOD;
		}
		b >>= 1;
		a = a * a % MOD;
	}
	return res;
}
ll inv(ll num) {
	return binexp(num, MOD - 2);
}
// *-> KISS*
int solve() {
    ll a, b; cin >> a >> b;
    ll n = a + b;
    ll m = (n + 1) >> 1;
    m %= MOD; a %= MOD; n %= MOD;
    cout << ((m * a % MOD) * inv(n) % MOD);
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
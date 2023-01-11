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

ll add(ll a, ll b) {
	return (a + b) % MOD;
}
ll mul(ll a, ll b) {
	return a * b % MOD;
}
const int MAXN = 1e6 + 1;
// *-> KISS*
int solve() {
    int n; cin >> n;
	vector<vector<int>> v(n);
	for (int i = 0; i < n; i++) {
		int k; cin >> k;
		vector<int> temp(k, 0);
		for(int ii = 0; ii < k; ++ii) cin >> temp[ii];
		v[i] = temp;
	}
	vector<vector<int>> dp(MAXN);
	for (int i = 0; i < n; i++) {
		for(auto& val : v[i]) {
			dp[val].push_back(i);
		}
	}
	ll ans = 0;
	for(int i = 1; i < MAXN; ++i) {
		ll chooseKid = modinv(n);
		for(int j = 0; j < sz(dp[i]); ++j) {
			ll chooseItem = modinv(sz(v[dp[i][j]]));
			ll anotherKid = mul(sz(dp[i]), modinv(n));
			ans = add(ans, mul(chooseKid, mul(chooseItem, anotherKid)));
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

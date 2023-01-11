#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)

typedef long double ld;
const int MOD = 1000000007;
#define ff first
#define ss second
using pll = pair<ll, ll>;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// *-> KISS*
int solve() {
	ll n, x; cin >> n >> x;
	vector<ll> w(n);
	for(int i = 0; i < n; ++i) cin >> w[i];
	vector<pll> dp(1 << n);
	// Base Case
	dp[0] = {1, 0};
	for(int i = 1; i < (1 << n); ++i) {
		dp[i] = {n + 1, 0};
		for(int j = 0; j < n; ++j) {
			if(i & (1 << j)) {
				pll p = dp[i ^ (1 << j)];
				if(p.ss + w[j] <= x) {
					p.ss += w[j];
				}
				else {
					p.ff++;
					p.ss = w[j];
					/* p.ss = min(p.ss, w[j]); */
				}
				dp[i] = min(dp[i], p);
			}
		}
	}
	cout << (dp[(1 << n) - 1].ff);
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

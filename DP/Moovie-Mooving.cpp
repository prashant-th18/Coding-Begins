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

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const ll MAX = (ll)1e15;
// *-> KISS*
int solve() {
	freopen("movie.in", "r", stdin);
	freopen("movie.out", "w", stdout);
	ll n, l; cin >> n >> l;
	vector<int> d(n);
	vector<vector<ll>> start(n);
	for(int i = 0; i < n; ++i) {
		cin >> d[i];
		int s; cin >> s;
		vector<ll> v(s);
		for(int ii = 0; ii < s; ++ii) cin >> v[ii];
		start[i] = v;
	}
	int ans = 40;
	vector<ll> dp(1 << n, MAX);
	dp[0] = l;
	for(int i = 1; i < (1 << n); ++i) {
		for(int j = 0; j < n; ++j) {
			if((i >> j) & 1) {
				ll ti = dp[i ^ (1 << j)];
				vector<ll>& v = start[j];
				auto it = lower_bound(all(v), ti - d[j]);
				if(it != end(v)) {
					dp[i] = min(dp[i], *it);
				}
			}
		}
		if(dp[i] == 0) ans = min(ans, __builtin_popcount(i));
	}
	if(ans == 40) ans = -1;
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

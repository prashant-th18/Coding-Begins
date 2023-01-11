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

// *-> KISS*
int solve() {
	int n; cin >> n;
	string s; cin >> s;
	s = "$" + s;
	vector<int> v(26);
	for(int i = 0; i < 26; ++i) cin >> v[i];
	vector<array<ll, 3>> dp(n + 1);
	dp[0][0] = 1; dp[0][1] = 0; dp[0][2] = 0;
	for(int i = 1; i <= n; ++i) {
		dp[i][0] = 0; dp[i][1] = 0; dp[i][2] = INT_MAX;
	}
	for(int i = 1; i <= n; ++i) {
		/* dp[i][0] = (dp[i][0] + dp[i - 1][0]) % MOD; */
		/* dp[i][1] = max(dp[i - 1][1], 1LL); */
		/* dp[i][2] = dp[i - 1][2] + 1; */
		ll cnt = 1, op = 0;
		for(int j = i - 1; j >= 0; --j) {
			// we are saying that we will cut at "j"
			if(op == 0) dp[i][0] = (dp[i][0] + dp[j][0]) % MOD;
			dp[i][1] = max({dp[j][1], cnt, dp[i][1]});
			if(!(j == 0 && i == n)) dp[i][2] = min({dp[i][2], op + dp[j][2] + 1});
			if(s[j] == s[j + 1]) {
				++cnt;
				if(cnt > v[s[j] - 'a']) ++op, cnt = 1;
			}
			else cnt = 1;
		}
	}
	dp[n][0]--;
	cout << dp[n][0] << ' ' << dp[n][1] << ' ' << dp[n][2] << '\n';
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

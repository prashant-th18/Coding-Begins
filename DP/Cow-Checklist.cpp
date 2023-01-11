#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
const int MOD = 1e9 + 7;
// *-> KISS*
using pll = pair<ll, ll>;

ll dist(pll a, pll b) {
	ll f = a.ff - b.ff;
	ll s = a.ss - b.ss;
	return f * f + s * s;
}
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("checklist.in", "r", stdin);
	freopen("checklist.out", "w", stdout);

	int n, m; cin >> n >> m;
	vector<pll> h(n), g(m);
	for(int i = 0; i < n; ++i) {
		cin >> h[i].ff >> h[i].ss;
	}
	for(int i = 0; i < m; ++i) {
		cin >> g[i].ff >> g[i].ss;
	}
	vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(m + 1, vector<ll>(2, 1e12)));
	// dp[i][j][k] -> 
	// We are currently at ith hol. and j'th g and k(0: means at hol, 1 means at g).
	// So, dp will tell me the min time to reach here
	// Base Case
	dp[1][0][0] = 0;
	for(int i = 0; i <= n; ++i) {
		for(int j = 0; j <= m; ++j) {
			if(i > 1) {
				dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][0] + dist(h[i - 1], h[i - 2]));
			}
			if(j > 1) {
				dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][1] + dist(g[j - 2], g[j - 1]));
			}
			if(i > 0 && j > 0) {
				dp[i][j][1] = min(dp[i][j][1], 
						dp[i][j - 1][0] + dist(h[i - 1], g[j - 1]));

				dp[i][j][0] = min(dp[i][j][0], 
						dp[i - 1][j][1] + dist(g[j - 1], h[i - 1]));
			}
		}
	}
	cout << dp[n][m][0];
	return 0;
}
// -> Keep It Simple Stupid!

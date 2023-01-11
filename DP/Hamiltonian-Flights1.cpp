#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
const int MOD = 1e9 + 7;
// *-> KISS*

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m; cin >> n >> m;
	vector<vector<int>> v(n);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; --a, --b;
		v[b].push_back(a);
	}
	vector<vector<int>> dp(n, vector<int>(1 << n, 0));
	dp[0][1] = 1;
	for(int j = 0; j < (1 << n); ++j) {
		for(int i = 0; i < n; ++i) {
			if((i != (n - 1)) && ((j >> (n - 1)) & 1)) continue;
			if(((j >> i) & 1) == 0) continue;
			for(int val : v[i]) {
				if((j >> val) & 1) {
					dp[i][j] = (dp[i][j] + dp[val][j ^ (1 << i)]) % MOD;
				}
			}
		}
	}
	cout << dp[n - 1][(1 << n) - 1];
	return 0;
}
// -> Keep It Simple Stupid!

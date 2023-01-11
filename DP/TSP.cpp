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
	int test = 1;
	//cin >> test;
	int n; cin >> n;
	vector<vector<int>> c(n, vector<int>(n, 0));
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) cin >> c[i][j];
	}

	vector<vector<int>> dp(n, vector<int>(1 << n, 1e9));
	for(int mask = 0; mask < (1 << n); ++mask) {
		for(int i = 0; i < n; ++i) {
			// dp[i][mask] -> Minimum cost to go from City i to every other city and then return to city 0
			if(mask == 0) dp[i][mask] = c[i][0];
			else {
				for(int j = 0; j < n; ++j) {
					if(mask & (1 << j)) {
						dp[i][mask] = min(dp[i][mask], c[i][j] + dp[j][mask ^ (1 << j)]);
					}
				}
			}
		}
	}
	cout << dp[0][(1 << n) - 1];
	return 0;
}
// -> Keep It Simple Stupid!

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

const int inf = (int)1e9;
// *-> KISS*
int solve() {
    int n, k; cin >> n >> k;
	vector<int> v(n), b(n);
	for(int i = 0; i < n; ++i) cin >> v[i];
	for(int i = 0; i < n; ++i) cin >> b[i];
	vector<vector<int>> dp(n, vector<int>(n, 0));
	// dp[i][j] -> Maximum sum I can get, If we consider a valid sequence of brackets from b[i .. j]
	// dp[i][j] (initial value = 0) -> Because in every case, we can consider not taking any subsequence
	for(int l = 1; l <= n; ++l) {
		for(int i = 0; i <= n - l; ++i) {
			int j = i + l - 1;
			if(l == 1) dp[i][j] = 0; // Empty sequence considered
			else if(l == 2) {
				if(b[j] - b[i] == k) dp[i][j] = max(dp[i][j], v[i] + v[j]);
				// b[i] & b[j] are matched
			}
			else {
				if(b[j] - b[i] == k) dp[i][j] = max(dp[i][j], v[i] + v[j] + dp[i + 1][j - 1]);
				// b[i] and b[j] are matched
				for(int kk = i; kk <= j - 1; ++kk) {
					dp[i][j] = max(dp[i][j], dp[i][kk] + dp[kk + 1][j]);
					// considering subsegments [i .. kk] & [kk + 1 .. j]
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j < n; ++j) {
			ans = max(ans, dp[i][j]);
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

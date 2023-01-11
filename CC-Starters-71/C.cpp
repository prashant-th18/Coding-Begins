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
    string a, b; cin >> a;
    b = a;
    reverse(all(b));
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for(int i = 1; i <= n - 1; ++i) {
    	for(int j = 1; j <= n - i; ++j) {
    		if(a[i - 1] == b[j - 1]) {
    			dp[i][j] = 1 + dp[i - 1][j - 1];
    		}
    		else {
    			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    		}
    		if(i == 3) {
    			// cout << j << ' ' << dp[i][j] << endl;
    		}
    	}
    }
    int ans = 0;
    for(int i = 0; i <= n; ++i) {
    	ans = max(ans, dp[i][n - i]);
    	// cout << ans << endl;
    }
    cout << ans;
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
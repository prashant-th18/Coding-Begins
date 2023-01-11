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
	string s; cin >> s;
	int n = sz(s);
	vector<vector<int>> dp(n, vector<int>(n, inf));
	for(int len = 1; len <= n; ++len) {
		for(int i = 0; i <= n - len; ++i) {
			int j = i + len - 1;
			if(len == 1) dp[i][j] = 1;
			else {
				if(s[i] == s[j]) {
					if(len == 2) dp[i][j] = 0;
					else dp[i][j] = dp[i + 1][j - 1];
				}
				for(int k = i; k <= j - 1; ++k) {
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
				}
			}
		}
	}
	cout << dp[0][n - 1];
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

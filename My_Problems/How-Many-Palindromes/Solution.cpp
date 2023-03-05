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
    string s; cin >> s;
	int n = sz(s);
	vector<vector<ll>> dp(n, vector<ll>(n, 0));
	// dp[i][j] -> Number of palindromes in string[i .. j]
	for(int l = 1; l <= n; ++l) {
		for(int i = 0; i <= n - l; ++i) {
			int j = i + l - 1;
			if(l == 1) dp[i][j] = 1;
			else if(l == 2) {
				dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] + (s[i] == s[j])) % MOD;
			}
			else {
				dp[i][j] = ((((dp[i + 1][j] + dp[i][j - 1]) % MOD - dp[i + 1][j - 1] + MOD) % MOD) + 
					(s[i] == s[j] ? dp[i + 1][j - 1] : 0)) % MOD;
			}
		}
	}
	int q; cin >> q;
	while(q--) {
		int l, r; cin >> l >> r; --l, --r;
		cout << dp[l][r] << '\n';
	}
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

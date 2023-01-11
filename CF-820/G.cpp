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
using pll = pair<ll, ll>;

int n, m;
string s, t;
vector<bool> is_pres;
vector<vector<pll>> dp; // min-moves, diff-optimal-subsequences
pll fun(int i, int j) {
	if(i > j) return {0, 1};
	if(dp[i][j].ff != INT_MAX) return dp[i][j];

	if(j - i + 1 < m) return dp[i][j] = {0, 1};

	for(int k = i; k <= j - (m - 1); ++k) {
		if(is_pres[k]) {
			pll f = fun(i, k - 1), s1 = fun(k + m, j);
			pll ans = {f.ff + 1 + s1.ff, f.ss * s1.ss % (MOD)};
			if(ans.ff < dp[i][j].ff) dp[i][j] = ans;
		}
	}
	if(dp[i][j].ff == INT_MAX) dp[i][j] = {0, 1};
	return dp[i][j];
}
// *-> KISS*
int solve() {
    cin >> s >> t;
	n = sz(s), m = sz(t);
	dp.assign(n, vector<pll>(n, pll(INT_MAX, 1)));
	is_pres.assign(n, false);
	for(int i = 0; i <= n - m; ++i) {
		is_pres[i] = ((s.substr(i, m) == t));
	}
	for(int len = 1; len <= n; ++len) {
		for(int i = 0; i <= n - len; ++i) {
			// s[i .. i + len - 1]
			fun(i, i + len - 1);
		}
	}
	cout << dp[0][n - 1].ff << ' ' << dp[0][n - 1].ss;
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

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
	ll n = sz(s);
	// [0 .. n - 1][used/un-used][going to start/started]
	vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(2, vector<ll>(2, 0)));
	for(int i = n - 1; i >= 0; --i) {

		// Unused
		dp[i][1][0] = dp[i][1][1] = (s[i] == '1' ? (i + 1) * (n - i) : 0) + dp[i + 1][1][0];

		// Used
		// Started (use krke kthm krdia)
		dp[i][0][1] = (s[i] == '1' ? (i + 1) * (n - i) : 0) + max(dp[i + 1][0][0], dp[i + 1][0][1]);

		// Used
		// Going to start
		dp[i][0][0] = (s[i] == '0' ? (i + 1) * (n - i) : 0) + max(dp[i + 1][1][0], dp[i + 1][0][0]);
	}
	cout << max({dp[0][0][0], dp[0][0][1], dp[0][1][0]});
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

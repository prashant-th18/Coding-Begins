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
	vector<int> v(n);
	for(int i = 0; i < n; ++i) cin >> v[i];
	vector<vector<int>> dp(n + 1, {0, 0}); // [0] -> me, [1] -> friend
	dp[1][0] = dp[0][1] = n + 1;
	dp[1][1] = (v[0] == 1);
	for(int i = 2; i <= n; ++i) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 2][1]);
		dp[i][1] = (v[i - 1] == 1) + dp[i - 1][0];
		dp[i][1] = min(dp[i][1], (v[i - 1] == 1) + (v[i - 2] == 1) + dp[i - 2][0]);
	}
	cout << min(dp[n][1], dp[n][0]);
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

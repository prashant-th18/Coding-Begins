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
    ll n, m; cin >> n >> m;
	vector<ll> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, -1e13));
	ll ans = LLONG_MIN;
	for(int i = n - 1; i >= 0; --i) {
		for(int j = 1; j <= m; ++j) {
			dp[i][j] = dp[i + 1][j];
			if(j == m) {
				dp[i][j] = max(dp[i][j], m * v[i]);
			}
			else {
				dp[i][j] = max(dp[i][j], v[i] * j + dp[i + 1][j + 1]);
			}
		}
		ans = max(ans, dp[i][1]);
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

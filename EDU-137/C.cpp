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
	string s; cin >> s;
	vector<ll> v(n);
	for(int i = 0; i < n; ++i) cin >> v[i];
	vector<vector<ll>> dp(n, vector<ll>(2, 0));
	// [0] -> not moved
	// [1] -> moved
	for(int i = 0; i < n; ++i) {
		if(i == 0) {
			if(s[i] == '0') {}
			else {
				dp[i][0] = v[i];
			}
		}
		else {
			if(s[i] == '0') {
				dp[i][0] = dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
			}
			else {
				// Either keep it here
				dp[i][0] = v[i] + (max(dp[i - 1][0], dp[i - 1][1]));
				// Don't keep it here
				dp[i][1] = v[i - 1] + dp[i - 1][1];
			}
		}
	}
	cout << max(dp[n - 1][0], dp[n - 1][1]);
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

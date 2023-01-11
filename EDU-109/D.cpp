// Great Explaination: https://codeforces.com/blog/entry/90793?#comment-792051
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
const int inf = 1e9;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// *-> KISS*
int solve() {
	int n; cin >> n;
	vector<int> x, y;
	for(int i = 0; i < n; ++i) {
		int t; cin >> t;
		if(t == 0) y.push_back(i);
		else x.push_back(i);
	}
	// x -> keeps indices of people
	// y -> keeps indices of empty places
	vector<vector<int>> dp(sz(x) + 1, vector<int>(sz(y) + 1, inf));
	dp[0][0] = 0; // this means if we consider 0 people and 0 empty places, what is the minimum time 
				  // to create a valid configuration
	for(int i = 0; i <= sz(x); ++i) {
		for(int j = 1; j <= sz(y); ++j) {
			// consider for j - 1 places
			dp[i][j] = min(dp[i][j], dp[i][j - 1]);

			if(i > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + abs(y[j - 1] - x[i - 1]));
		}
	}
	cout << dp[sz(x)][sz(y)];
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

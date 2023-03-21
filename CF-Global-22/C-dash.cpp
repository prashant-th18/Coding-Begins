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
	int odd = 0, even = 0;
	for(int i = 0; i < n; ++i) {
		int t; cin >> t;
		if(t % 2 == 0) ++even;
		else ++odd;
	}
	vector<vector<vector<bool>>> dp(even + 1, vector<vector<bool>>(odd + 1, vector<bool>(2, false)));
	for(int i = 0; i <= even; ++i) {
		for(int j = 0; j <= odd; ++j) {
			// Alice -> Even
			if(i != 0) {
				if(j & 1) {
					dp[i][j][0] = dp[i - 1][j][1];
				}
				else {
					dp[i][j][0] = !dp[i - 1][j][1];
				}
			}
		}
	}
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